t = int(input())
for z in xrange(t):
	n, m = map(int, raw_input().split())
	g = []
	for x in xrange(n):
		g.append(map(int, list(raw_input())))
	h = []
	for x in xrange(n):
		for y in xrange(m):
			if g[x][y] == 1:
				h.append((x, y))
	d = {}
	for x in xrange(1, n+m-1):
		d[x] = 0
	for x in range(len(h)):
		for y in range(x+1, len(h)):
			dist = abs(h[x][0]-h[y][0]) + abs(h[x][1]-h[y][1])
			d[dist] += 1
	o = ''
	for x in xrange(1, n+m-1):
		o += str(d[x]) + ' '
	print o[:-1]