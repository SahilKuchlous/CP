t = int(input())

for x in xrange(t):
	n = int(input())
	a = map(int, raw_input().split())
	
	inf = True
	s = a[0]
	for x in xrange(n):
		if a[x] != -1 and a[x] != s+x:
			inf = False
	if inf:
		print 'inf'
		continue

	last = 0
	last_i = 0
	imp = False
	for x in xrange(n-1):
		if a[x] != -1:
			last = a[x]
			last_i = x
		if a[x+1] - (last + (x-last_i)) > 1:
			print 'impossible'
			imp = True
			break
	if imp:
		break

	last = a[0]
	last_i = 1
	d = -1
	for x in range(1, n):
		if a[x] != -1:
			if a[x] < last + (x-last_i):
				cd = s+(x-a[x])
				if a[cd+1] > a[cd]:
					imp = True
					break
			last = a[x]
			last_i = x
	print d