t = int(input())
for z in range(t):
	k, n = map(int, raw_input().split())
	s = []
	for x in range(k):
		a, b = map(int, raw_input().split())
		s.append((a, b))
	if k >= 4:
		print 'yes'
		continue
	xb = []
	yb = []
	xyb = []
	for x in s:
		if x[0] == n-1 or x[0] == 0:
			xb.append(x)
		if x[1] == n-1 or x[1] == 0:
			yb.append(x)
		if (x[0] == n-1 or x[0] == 0) and (x[1] == n-1 or x[1] == 0):
			xyb.append(x)
	if len(xyb) > 0:
		print 'yes'
		continue
	if len(xb) >= 2:
		print 'yes'
		continue
	if len(yb) >= 2:
		print 'yes'
		continue
	if len(xb) == 1 and len(yb) == 1 and len(s) == 3:
		print 'yes'
		continue
	if len(xb) == 1 and len(s) == 3:
		ss = sorted(s, key = lambda x: x[0])
		if ss[1] != xb[0]:
			print 'yes'
			continue
	if len(yb) == 1 and len(s) == 3:
		ss = sorted(s, key = lambda x: x[1])
		if ss[1] != yb[0]:
			print 'yes'
			continue
	print 'no'