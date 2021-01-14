import math
n, s, m = map(int, raw_input().split())
o = math.pow(s, n)
for x in range(2, n+1):
	o -= s * math.pow(s-1, (x-1)/2) * math.pow(s, n-x)
print int(o%m)