from fractions import Fraction
t = int(input())
for z in range(t):
	n, a, k = map(int, raw_input().split())
	angle_sum = 180*(n-2)
	part = Fraction(2*(angle_sum-a*n), (n*(n-1)))
	angle_k = a + part*(k-1)
	print angle_k.numerator, angle_k.denominator