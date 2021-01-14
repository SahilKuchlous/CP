t = int(input())
for z in range(t):
	n, k = map(int, raw_input().split())
	s = map(int, raw_input().split())
	s.sort(reverse = True)
	l = s[k-1]
	c=k
	for x in range(k, n):
		if s[x] == l:
			c += 1
	print c