t = int(input())
for z in range(t):
	n = int(input())
	a = map(int, raw_input().split())
	flag = True
	out = True
	for x in xrange(n-1):
		if a[x] > a[x+1]:
			if flag:
				flag = False
			else:
				out = False
				break
		if not flag and a[x+1] > a[0]:
			out = False
			break
	if out:
		print 'YES'
	else:
		print 'NO'