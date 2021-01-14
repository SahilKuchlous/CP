import math

t = int(input())

for z in range(t):
	m, x, y = map(int, raw_input().split())
	d = x*1.0/y*1.0
	a = []
	for b in range(1,m+1):
		a.append(b)
	while len(a) > 2:
		a1 = []
		a2 = []
		for x in range(len(a)):
			if x%2 == 0:
				a1.append(a[x])
			else:
				a2.append(a[x])
		al = len(a1)
		au = int(math.floor(al*d))
		a1.pop(au)
		a2.pop(au)
		a = a1+a2
	print a[0]^a[1]