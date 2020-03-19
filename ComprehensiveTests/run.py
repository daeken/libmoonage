import struct
from capstone import *
from subprocess import PIPE, Popen

md = Cs(CS_ARCH_ARM64, CS_MODE_ARM)

stateOffsets = {}
def addOffsets(name, offset, size):
    for i in xrange(size):
        stateOffsets[offset + i] = name

addOffsets('PC', 0, 8)
addOffsets('SP', 8, 8)
for i in xrange(31):
    addOffsets('X%i' % i, 16 + 8 * i, 8)
for i in xrange(32):
    addOffsets('V%i' % i, 16 + 8 * 32, 16)

addOffsets('Exclusive8', 16 + 8 * 32 + 16 * 32, 1)
addOffsets('Exclusive16', 16 + 8 * 32 + 16 * 32 + 1, 2)
addOffsets('Exclusive32', 16 + 8 * 32 + 16 * 32 + 3, 4)
addOffsets('Exclusive64', 16 + 8 * 32 + 16 * 32 + 7, 8)
addOffsets('NZCV_N', 16 + 8 * 32 + 16 * 32 + 15, 8)
addOffsets('NZCV_Z', 16 + 8 * 32 + 16 * 32 + 15 + 8, 8)
addOffsets('NZCV_C', 16 + 8 * 32 + 16 * 32 + 15 + 8 * 2, 8)
addOffsets('NZCV_V', 16 + 8 * 32 + 16 * 32 + 15 + 8 * 3, 8)

#popen = Popen('./comprehensivetests', stdout=PIPE)
tests = {}
failed = [None, None, None] # cause, instruction, testcase
lines = file('log', 'r').read().split('\n')
#while True:
for line in lines:
    #line = popen.stdout.readline()
    if not line:
        break
    line = line.strip()
    stat = line.split(' ')
    if stat[0] == 'if':
        failed[0] = 'interpreter failed'
    elif stat[0] == 'rf':
        failed[0] = 'recompiler failed'
    elif stat[0] == 'df':
        failed[0] = 'disassembler failed'
        failed[1] = int(stat[1], 16)
        failed[2] = None
    elif stat[0] == 'mm*':
        failed[0] = 'state mismatch at 0x%x (in %s)' % (int(stat[1]), stateOffsets[int(stat[1])])
    elif stat[0] == 'fi':
        failed[1] = int(stat[1], 16)
        failed[2] = int(stat[2])
    elif stat[0] == 'mf':
        tests[stat[1]] = dict(index=int(stat[2]), cause=failed[0], instruction=failed[1], testcase=failed[2])
        failed = [None, None, None] # cause, instruction, testcase
    elif stat[0] == 'ms':
        tests[stat[1]] = True
    else:
        print 'Unknown status command', `stat[0]`
        break

for mnem in sorted(tests.keys()):
    status = tests[mnem]
    if status is True:
        print mnem, '-- succeeded'
    else:
        x = list(md.disasm(struct.pack('<I', status['instruction']), 0x100000000))[0]
        print mnem, '-- #%i' % status['index'],
        if status['testcase'] is not None:
            print '(%i)' % status['testcase'],
        print status['cause'], '::', x.mnemonic, x.op_str
