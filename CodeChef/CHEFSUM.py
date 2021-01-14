t = int(input())
for z in range(t):
	n = int(input())
	a = map(int, raw_input().split())
	m = 100001
	mi = 0
	for x in range(n):
		if a[x] < m:
			m = a[x]
			mi = x
	print mi+1