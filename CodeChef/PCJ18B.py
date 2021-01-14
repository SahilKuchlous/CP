t = int(input())
for z in range(t):
	n = int(input())
	o = 0
	for x in range(1, n+1, 2):
		o += (n-x+1)**2
	print o