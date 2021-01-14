import math

t = int(input())

for c in range(t):
	
	n, l, b, h = map(int, raw_input().split())
	x = [0, l]
	y = [0, b]
	z = [0, h]

	for a in range(n):
		x1, y1, z1 = map(int, raw_input().split())
		x.append(x1)
		y.append(y1)
		z.append(z1)

	x = sorted(x)
	mx = x[1]-x[0]
	for a in range(len(x)-1):
		if x[a+1]-x[a] > mx:
			mx = x[a+1]-x[a]

	y = sorted(y)
	my = y[1]-y[0]
	for a in range(len(y)-1):
		if y[a+1]-y[a] > my:
			my = y[a+1]-y[a]

	z = sorted(z)
	mz = z[1]-z[0]
	for a in range(len(z)-1):
		if z[a+1]-z[a] > mz:
			mz = z[a+1]-z[a]

	print int((mx*my*mz)%(math.pow(10, 9)+7))