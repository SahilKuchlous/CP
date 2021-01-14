t = int(input())

for x in range(t):
	a = raw_input().split()
	b = raw_input().split()
	c = 0
	for x in a:
		if x in b:
			c += 1
	if c >= 2:
		print 'similar'
	else:
		print 'dissimilar'