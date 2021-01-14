import math
t = int(input())

for z in range(t):
	n, q = map(int, raw_input().split())
	d = map(int, raw_input().split())
	p = map(int, raw_input().split())
	dp = reduce(lambda x, y: x*y, d)
	for x in p:
		print int(math.floor(x/dp))