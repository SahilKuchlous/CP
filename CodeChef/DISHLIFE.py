t = int(input())

for a in range(t):

	n, k = map(int, raw_input().split())
	kfreq = [0 for x in range(k+1)]
	b = []
	for x in range(n):
		c = map(int, raw_input().split())[1:]
		for item in c:
			kfreq[item] += 1
		b.append(c)

	o = ''

	for x in b:
		d = 0
		bfreq = [0 for z in range(k+1)]
		sx = set(x)
		for item in x:
		  bfreq[item] += 1
		for y in sx:
			print x, y, bfreq[y], kfreq[y]
			if bfreq[y] < kfreq[y]:
				d += 1
			else:
				break
		print d, len(sx)
		if d == len(sx):
			o = 'some'
			break

	for x in range(1, k+1):
		if kfreq[x] == 0:
			o = 'sad'
			break

	if o == '':
		print 'all'
	else:
		print o