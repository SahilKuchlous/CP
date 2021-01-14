t = int(input())
for z in range(t):
	n = int(input())
	a = map(int, raw_input().split())
	m = []
	for x in range(n):
		m.append(0)
	m[-1] = a[-1]
	c = 10**10
	for x in range(n-2, -1, -1):
		if a[x] > m[x+1]:
			m[x] = m[x+1]
			if a[x] < c:
				c = a[x]
		else:
			m[x] = a[x]
	print len([x for x in a if x >= c])