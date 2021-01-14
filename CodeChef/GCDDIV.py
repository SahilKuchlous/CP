import fractions
import math

t = int(input())

for z in range(t):
	n, k = map(int, raw_input().split())
	a = map(int, raw_input().split())
	g = reduce(fractions.gcd, a)
	b = 2

	while b<=k and g>0:
		if g%b == 0:
			g /= b
		else:
			b += 1
	if g > 1:
		print 'NO'
	else:
		print 'YES'

	'''
	flag = True
	c = int(math.ceil(math.sqrt(g)))
	if k>g:
		print 'YES'
	elif k+1 > c:
		print 'NO' 
	else:
		for x in range(k+1, int(math.ceil(math.sqrt(g)))):
			if g%x == 0:
				flag = False
		if flag:
			print 'YES'
		else:
			print 'NO'
	'''