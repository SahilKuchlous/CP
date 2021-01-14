t = int(input())
for z in range(t):
	n = int(input())
	d = {}
	for x in range(n):
		a, b = map(int, raw_input().split())
		if a in d:
			d[a].add(b)
		else:
			d[a] = set([b])
		if b in d:
			d[b].add(a)
		else:
			d[b] = set([a])
	while len(d) > 1:
		for x in d:
			if len(d[x]) == 1: