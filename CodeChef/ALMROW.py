t = int(input())

for z in range(t):
	n = int(input())
	p = {1: [2], n: [n-1]}
	for x in range(2, n):
		p[x] = [x+1, x-1]
	k = int(input())
	for x in range(k):
		a, b = map(int, raw_input().split())
		p[a].append(b)
		p[b].append(a)
	s = 0
	c = {}
	for x in range(1, n):
		checked = []
		border = []
		new = []
		

