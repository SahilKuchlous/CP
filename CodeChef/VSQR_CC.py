import math

def derangment(n):
	p2 = math.factorial(n)
	term = p2

	for x in range(1, n+1):
		calc = term/x
		der = (calc * int(math.pow(-1, x)))
		p2 += der
		p2 = p2%(int(math.pow(10,9)+7)) 
		term = calc

	output = int(p2)
	return output

t = int(input())

for e in range(t):
	no = int(input())
	ans = derangment(no)
	print(ans)	