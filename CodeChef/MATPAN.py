t = int(input())

for z in range(t):

	p = map(int, raw_input().split())
	c = list('abcdefghijklmnopqrstuvwxyz')
	s = raw_input()
	for x in s:
		if x in c:
			c.remove(x)
	sum = 0
	for x in c:
		sum += p[ord(x)-ord('a')]
	print sum
