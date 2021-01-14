import math

t = int(input())

def cang(a, c):
	
	global q
	global b
	x = c[0]
	y = c[1]
	
	if x > 0:
		if a[x-1][y] != '.' and a[x-1][y] != '?':
			return False
	
	if x < b-1:
		if a[x+1][y] != '.' and a[x+1][y] != '?':
			return False

	if y > 0:
		if a[x][y-1] != '.' and a[x][y-1] != '?':
			return False

	if y < b-1:
		if a[x][y+1] != '.' and a[x][y+1] != '?':
			return False

	return True

def canb(a, c):
	
	global q
	global b
	x = c[0]
	y = c[1]
	
	if x > 0:
		if a[x-1][y] != '.' and a[x-1][y] != 'B' and a[x-1][y] != '?':
			return False
	
	if x < b-1:
		if a[x+1][y] != '.' and a[x+1][y] != 'B' and a[x+1][y] != '?':
			return False

	if y > 0:
		if a[x][y-1] != '.' and a[x][y-1] != 'B' and a[x][y-1] != '?':
			return False

	if y < b-1:
		if a[x][y+1] != '.' and a[x][y+1] != 'B' and a[x][y+1] != '?':
			return False

	return True

def canp(a, c):
	
	global q
	global b
	x = c[0]
	y = c[1]
	
	if x > 0:
		if a[x-1][y] != '.' and a[x-1][y] != 'P' and a[x-1][y] != '?':
			return False
	
	if x < b-1:
		if a[x+1][y] != '.' and a[x+1][y] != 'P' and a[x+1][y] != '?':
			return False

	if y > 0:
		if a[x][y-1] != '.' and a[x][y-1] != 'P' and a[x][y-1] != '?':
			return False

	if y < b-1:
		if a[x][y+1] != '.' and a[x][y+1] != 'P' and a[x][y+1] != '?':
			return False

	return True

def fill(a, c):

	global n
	global q

	# print a, c, cang(a, c), canb(a, c), canp(a, c), n

	if c == len(q) - 1:
		if cang(a, q[c]):
			n += 1
		if canb(a, q[c]):
			n += 1
		if canp(a, q[c]):
			n += 1
		return

	else:

		x = q[c][0]
		y = q[c][1]
		next = c+1

		if cang(a, q[c]):
			a[x][y] = 'G'
			fill(a, next)
			a[x][y] = '?'

		if canb(a, q[c]):
			a[x][y] = 'B'
			fill(a, next)
			a[x][y] = '?'

		if canp(a, q[c]):
			a[x][y] = 'P'
			fill(a, next)
			a[x][y] = '?'

def check(a):
	global b
	for x in range(b):
		for y in range(b):
			if g[x][y] == 'G' and cang(a, (x, y)) == False:
				return False
			elif g[x][y] == 'P' and canp(a, (x, y)) == False:
				return False
			elif g[x][y] == 'B' and canb(a, (x, y)) == False:
				return False
	return True

for z in range(t):

	b = int(input())

	g = []
	for x in range(b):
		g.append(list(raw_input()))

	if not check(g):
		print 0
		continue

	q = []
	for x in range(b):
		for y in range(b):
			if g[x][y] == '?':
				q.append((x, y))

	if len(q) == 0:
		print 1
		continue

	q = sorted(q, key = lambda x: x[0]*10 + x[1])

	n = 0

	fill(g, 0)

	print int(n%(math.pow(10, 9) + 7))

