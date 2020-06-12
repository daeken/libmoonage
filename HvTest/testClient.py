from socket import *
import struct

c = socket(AF_INET, SOCK_STREAM)
c.connect(('10.0.0.39', 12347))

inRegs = {
	0 : 0x123, 
	1 : 0x100, 
	32 : 0x450000000 # PC
}

outRegs = [34]

inMem = {
	0x450000000 : '\x1f\x60\x21\x8b'
}

outMem = []

def write(v):
	c.send(struct.pack('<Q', v))

def read():
	return struct.unpack('<Q', c.recv(8))[0]

for n, v in inRegs.items():
	write(1)
	write(n)
	write(v)

for addr, data in inMem.items():
	write(2)
	write(addr)
	write(len(data))
	c.send(data)

for n in outRegs:
	write(3)
	write(n)

for addr in outMem:
	write(4)
	write(addr)

write(0)

if read() == 0:
	print 'Failed!'
else:
	print 'Succeeded!'
	nregs = read()
	for i in xrange(nregs):
		print 'Register %i -- 0x%x' % (read(), read())
	nmem = read()
