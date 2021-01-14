n, k = map(int, raw_input().split())
a = map(int, raw_input().split())
o=0
a = sorted(a)

d = [0]*(n-1)
for x in range(n-1):
	d[x] = a[x+1]-a[x]

i = -1
s = 0
for x in range(n-1):
	while True:
		if i<n-1:
			if s >= k:
				o += n-i-1
				s = s-d[x]
				break
			else:
				i += 1
				if i >= n-1:
					break 
			s += d[i]
			if s >= k:
				continue
		else:
			break
if s >= k:
	o += 1
print o