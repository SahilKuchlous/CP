import math
t = int(input())
for z in range(t):
	n, b = map(int, raw_input().split())
	o = int(math.floor((1-(1.0/b))*n+1))
	print o