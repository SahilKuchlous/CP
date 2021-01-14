n, d = map(int, raw_input().split())
c = []
for z in range(n):
	i = int(input())
	c.append(i)
c = sorted(c)
i = 0
o = 0
while i < n-1:
	if c[i+1] - c[i] <= d:
		o += 1
		i += 2
	else:
		i += 1
print o