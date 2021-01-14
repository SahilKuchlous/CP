n, k = map(int, raw_input().split())
h = map(int, raw_input().split())

'''
h = sorted(h)
i = n-1
o = 0
f = True
for x in range(n):
	for y in range(i, -1, -1):
		if y > x:
			if h[x]+h[y] < k:
				o += y-x
				i = y
				break
		else:
			f = False
			break
	if not f:
		break
print o
'''

h = sorted(h)+[10000000]
o = 0
for x in range(n):
	y = k-h[x]
	if y > 0:
		high = n-1
		low = x+1
		mid = 0
		while high >= low:
			mid = (high+low)/2
			if y <= h[mid]:
				high = mid-1
			elif y > h[mid+1]:
				low = mid+1
			else:
				o += mid - x
				break
print o