# For each number, calculate best with the first included and without

n = int(input())
a = map(int, raw_input().split())
'''
if n > 3:
	b = [0]*n
	c = [0]*n
	d = [0]*n
	b[0] = a[0]
	b[1] = a[1]
	c[0] = 1
	for x in range(2, n):
		b[x] = min(b[x-1], b[x-2]) + a[x]
		if b[x-1] < b[x-2]:
			if c[x-1] == 1:
				c[x] = 1
		elif b[x-2] < b[x-1]:
			if c[x-2] == 1:
				c[x] = 1
		else:
			if c[x-1] == 1 or c[x-2] == 1:
				c[x] = 1
	if b[-2] < b[-1]:
		if c[-2] == 1:
			print b[-2]
		else:
			print b[-1]
	else:
		print b[-1]
elif n > 2:
	print sum(sorted(a)[:2])
else:
	print min(a)
'''
if n > 3:
	b = [0]*n
	c = [0]*n
	b[0] = a[0]
	b[1] = a[1]
	c[0] = a[0]
	c[1] = a[0]+a[1]
	for x in range(2, n):
		b[x] = min(b[x-1], b[x-2]) + a[x]
		c[x] = min(c[x-1], c[x-2]) + a[x]
	print min(b[-1], c[-2])
elif n > 2:
	print sum(sorted(a)[:2])
else:
	print min(a)