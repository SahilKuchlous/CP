t = int(input())
for z in range(t):
	n, l = map(int, raw_input().split())
	a = []
	a = map(int, raw_input().split())
	f = []
	for x in xrange(2, a[0]+1):
		if a[0]%x == 0:
			if a[1]%x == 0:
				f.append([a[0]/x, x])
			else:
				f.append([x, a[0]/x])
			break
	for x in range(1, l):
		t = f[x-1][1], a[x]/f[x-1][1]
		f.append(t)
	p = [f[0][0]]
	for x in f:
		if x[1] not in p:
			p.append(x[1])
	p = sorted(p)
	d = {}
	l = 65
	for x in p:
		d[x] = chr(l)
		l += 1
	o = []
	o.append(d[f[0][0]])
	for x in f:
		o.append(d[x[1]])
	print 'Case #' + str(z+1) + ': ' + ''.join(o)