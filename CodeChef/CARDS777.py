import sys

sys.setrecursionlimit(1000000)

dic = {}

def opt(r, b, p, d):

	global dic

	q = (r+b)-p

	if (r, b, p) in dic:
		# print ('  '*d), r, b, p, q, dic[(r, b, p)]
		return dic[(r, b, p)]

	if r == 0 or p == 0:
		# print ('  '*d), r, b, p, q, min(b, q)
		return min(b, q)
	elif b == 0 or q == 0:
		# print ('  '*d), r, b, p, q, min(r, p)
		return min(r, p)
	
	r1 = (r/(r+b)) * (1 + opt(r-1, b, p-1, d+1))
	r2 = (b/(r+b)) * (opt(r, b-1, p-1, d+1))
	rv = r1 + r2

	b1 = (b/(r+b)) * (1 + opt(r, b-1, p, d+1))
	b2 = (r/(r+b)) * (opt(r-1, b, p, d+1))
	bv = b1 + b2

	# print ('  '*d), r, b, p, q, max(rv, bv), rv, bv
	dic[(r, b, p)] = max(rv, bv)
	return max(rv, bv)

t = int(input())

for z in range(t):

	ri, bi, pi = map(float, raw_input().split())
	for r in range(int(ri)):
		for b in range(int(bi)):
			for p in range(int(min(r+b, pi))):
				opt(r, b, p, 1)

	print opt(ri, bi, pi, 1)