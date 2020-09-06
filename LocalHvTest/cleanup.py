import xml.etree.ElementTree as ET
import struct
from capstone import *

def parseHex(data):
	return '\n'.join(x.strip() for x in data.split('\n'))

def diff(a, b):
	if a == b:
		return a
	mlen = min(len(a), len(b))
	ret = ''
	for (x, y) in zip(a[:mlen], b[:mlen]):
		if x == y:
			ret += x
		else:
			ret += '<font color="red">%s</font>' % x
	return ret + '<font color="green">%s</font>' % a[mlen:]

tree = ET.parse('testresults.xml')
root = tree.getroot()
insns = []
for insn in root:
	children = list(insn)
	name = children[0].text
	if children[1].tag == 'pre':
		insns.append(dict(name=name, exc=children[1].text))
		continue
	insn = disasm = failure = None
	preconditions = []
	postconditions = []

	for child in children[1:]:
		if child.tag == 'instruction':
			insn = struct.unpack('<I', child.text.replace(' ', '').decode('hex'))[0]
		elif child.tag == 'disasm':
			disasm = child.text
		elif child.tag == 'failure':
			failure = child.text
		elif child.tag == 'preconditions':
			for pc in child:
				key = pc[0].text
				if pc[1].text is None:
					value = parseHex(pc[1][0].text)
				else:
					value = pc[1].text
				preconditions.append((key, value))
		elif child.tag == 'postconditions':
			for pc in child:
				key = pc[0].text
				if pc[1].text is None:
					ev = parseHex(pc[1][0].text)
				else:
					ev = pc[1].text
				if pc[2].text is None:
					gv = parseHex(pc[2][0].text)
				else:
					gv = pc[2].text
				if key == 'NZCV':
					ev = int(ev[2:], 16)
					gv = int(gv[2:], 16)
					postconditions.append(('NZCV-N', str((ev >> 31) & 1), str((gv >> 31) & 1)))
					postconditions.append(('NZCV-Z', str((ev >> 30) & 1), str((gv >> 30) & 1)))
					postconditions.append(('NZCV-C', str((ev >> 29) & 1), str((gv >> 29) & 1)))
					postconditions.append(('NZCV-V', str((ev >> 28) & 1), str((gv >> 28) & 1)))
				else:
					postconditions.append((key, ev, gv))

	insns.append(dict(name=name, insn=insn, disasm=disasm, failure=failure, preconditions=preconditions, postconditions=postconditions))

print '''<script>
function copyTest(id) {
	console.log(id);
	let elem = document.getElementById('test-' + id);
	console.log(elem);
	elem.select();
	document.execCommand('copy');
	return false;
}
</script>'''
print '<h1>%i/322 Failing Tests</h1>' % len(insns)
print '<ul>'
for insn in insns:
	if 'exc' in insn:
		print '\t<li><a href="#%s">%s</a> -- Exception</li>' % (insn['name'], insn['name'])
	else:
		print '\t<li><a href="#%s">%s</a> -- %s -- <code>%s</code></li>' % (insn['name'], insn['name'], insn['failure'], insn['disasm'])
print '</ul>'

md = Cs(CS_ARCH_ARM64, CS_MODE_ARM)

for insn in insns:
	print
	print '<h1><a name="%s">%s</a></h1>' % (insn['name'], insn['name'])
	if 'exc' in insn:
		print '<pre>%s</pre>' % insn['exc']
		continue

	print 'Instruction bytes: <code>%s</code><br>' % ' '.join('%02X' % ord(c) for c in struct.pack('<I', insn['insn']))
	print 'Instruction: <code>0x%08x</code><br>' % insn['insn']
	print 'Moonage disassembly: <code>%s</code><br>' % insn['disasm']
	hc = False
	for (address, size, mnemonic, op_str) in md.disasm_lite(struct.pack('<I', insn['insn']), 0x450000000):
		print 'Capstone disassembly: <code>%s %s</code><br>' % (mnemonic, op_str)
		hc = True
	if not hc:
		print '<b>Capstone disassembly failed! Bad instruction?</b><br>'
	print '<br>'
	print 'Failure: %s<br>' % insn['failure']
	pc = insn['preconditions']
	hasMem = False
	if pc:
		print '<h3>Preconditions</h3>'
		print '<table border="1">'
		print '<tr><th>Key</th><th>Value</th></tr>'
		for key, value in pc:
			if key[0] == '0':
				hasMem = True
			print '<tr><td>%s</td>' % key
			print '<td><pre>%s</pre></td></tr>' % value
		print '</table>'
	pc = insn['postconditions']
	if pc and insn['failure'] != 'Execution':
		print '<h3>Postconditions</h3>'
		print '<table border="1">'
		print '<tr><th></th><th>Key</th><th>Emu</th><th>Cpu</th></tr>'
		for key, ev, gv in pc:
			if key[0] == '0':
				hasMem = True
			print '<tr><td>%s</td>' % ('&#x2705;' if ev == gv else '&#x274C;')
			print '<td>%s</td>' % key
			print '<td><pre>%s</pre></td>' % diff(ev, gv)
			print '<td><pre>%s</pre></td></tr>' % diff(gv, ev)
		print '</table>'
	if not hasMem:
		print '<a href="#" onclick="return copyTest(\'%s\')">Copy unit test</a>' % insn['name']
		print '<textarea style="opacity: 0.01; height: 0; position: absolute; z-index: -1;" id="test-%s">' % insn['name']
		print '\t\t[Test]'
		print '\t\tpublic void %s() =>' % insn['name'].replace('-', '_').replace('[', '').replace(']', '')
		print '\t\t\tnew InsnTest {'
		print '\t\t\t\tClass = "%s",' % insn['name']
		print '\t\t\t\tInstruction = 0x%08x,' % insn['insn']
		pc = insn['preconditions']
		if pc:
			print '\t\t\t\tPreconditions = {'
			for key, value in pc:
				print '\t\t\t\t\t["%s"] = %s, ' % (key, 'ToVector("%s")' % value if key[0] == 'V' else value)
			print '\t\t\t\t},'
		pc = insn['postconditions']
		if pc:
			print '\t\t\t\tPostconditions = {'
			for key, _, value in pc:
				print '\t\t\t\t\t["%s"] = %s, ' % (key, 'ToVector("%s")' % value if key[0] == 'V' else value)
			print '\t\t\t\t}'
		print '\t\t\t}.Run();'
		print '</textarea>'
