t = int(input())
for z in range(t):
	n = int(input())
	a = []
	for x in range(n):
		a.append(map(int, raw_input().split()))
	m = 0
	for x in range(n):
		s1 = 0
		s2 = 0
		for y in range(n-x):
			s1 += a[y][x+y]
			s2 += a[x+y][y]
		if s1 > m:
			m = s1
		if s2 > m:
			m = s2
	print m