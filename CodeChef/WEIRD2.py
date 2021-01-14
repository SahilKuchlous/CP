t = int(input())
for z in xrange(t):
	n = int(input())
	a = map(int, raw_input().split())
	num = list(set(a))
	dTemp = {}
	for x in a:
		if x in dTemp:
			dTemp[x] += 1
		else:
			dTemp[x] = 1
	d = []
	for x in dTemp:
		d.append((x, dTemp[x]))
	d1 = sorted(d, key = lambda x: x[0])
	d2 = sorted(d, key = lambda x: x[1])
	r1 = {}
	for x in d:
		r1[x] = len(d)
	i = 0
	for x in d1:
		for y in xrange(i, len(d)):
			if x[0] <= d2[y][1]:
				r1[x] = y
				i = y
				break
	c = 0
	for x in d1:
		for y in xrange(r1[x], len(d)):
			if x[1] >= d2[y][0]:
				c += 1
	print c