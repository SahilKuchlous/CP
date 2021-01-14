import fractions
import math
import sys

t = int(input())

for e in range(t):

	l1 = raw_input().split(' ')
	l1 = map(int, l1)
	hcf = l1[0]
	sqrt = False
	for x in l1:
		if int(math.sqrt(x)) == math.sqrt(x):
			print(int(math.sqrt(x)))
			sqrt = True
		if x == l1[0]:
			continue
		oldHcf = hcf
		hcf = fractions.gcd(hcf, x)
		if hcf == 1:
			hcf = oldHcf

	if sqrt == False:
		print(hcf)
	