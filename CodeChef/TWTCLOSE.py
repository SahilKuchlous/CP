n, k = map(int, raw_input().split())
p = {}
for x in range(1, n+1):
	p[x] = False
for x in range(k):
	t = raw_input().split()
	if t[0] == 'CLICK':
		p[int(t[1])] = not p[int(t[1])]
	else:
		for y in p:
			p[y] = False
	print len([x for x in p if p[x] == True])
