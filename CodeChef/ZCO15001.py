n = int(input())
a = map(int, raw_input().split())
c = 0
i = 0
while i<n:
	for x in range(n, i, -1):
		b = a[i:x]
		r = a[i:x][::-1]
		if b == r:
			c += 1
			i = x
			break
print c