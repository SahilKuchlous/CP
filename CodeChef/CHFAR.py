t = int(input())
for z in range(t):
	n, k = map(int, raw_input().split())
	a = map(int, raw_input().split())
	c = len([x for x in a if x != 1])
	if c <= k:
		print 'YES'
	else:
		print 'NO'