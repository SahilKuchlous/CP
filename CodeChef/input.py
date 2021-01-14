import random

with f = File.open("input", "w"):
	nc = random.randint(1, 100000)
	nv = random.randint(1, 100000)
	nw = random.randint(1, 100000)
	print >> f, nc + ' ' + nv + ' ' + nw
	for x in range(nc):
		c1 = random.randint(1, 100000)
		c2 = random.randint(c1, 100000)
		print >> f, nc + ' ' + nv + ' ' + nw
	v = []
	for x in range(nv):
		v.append(random.randint(1, 100000))
	print >> f, ' '.join(map(str, v))
	w = []
	for x in range(nw):
		w.append(random.randint(1, 100000))
	print >> f, ' '.join(map(str, w))