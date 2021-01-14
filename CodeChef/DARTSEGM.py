import math

n = int(input())
c1 = []
for x in range(n):
	c1.append(map(int, raw_input().split()))
q = int(input())
for x in range(q):
	l, r = map(int, raw_input().split())
	c2 = c1[l-1:r]
	m = 0
	for y in range(0, r-l+1):
		for z in range(0, r-l+1):
			d = math.pow(c2[y][0] - c2[z][0], 2) + math.pow(c2[y][1] - c2[z][1], 2)
			if d>m:
				m = d
	print int(m)
