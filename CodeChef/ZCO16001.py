inp = map(int, raw_input().split())
n = inp[0]
k = inp[1]
b1 = inp[2:n+2]
b2 = inp[n+2:]
b1 = sorted(b1)
b2 = sorted(b2)
print b1, b2
if len(b1) > 1:
	for x in range(k):
		if b1[-2] > b2[-2] and b1[0] < b2[-1]:
			l = b2[-1]
			s = b1[0]
			for y in range(n-1):
				if b1[y+1] < l:
					b1[y] = b1[y+1]
				else:
					b1[y] = l
					break
				if y == n-2:
					b1[n-1] = l
			for y in range(n-1, 0, -1):
				if b2[y-1] > s:
					b2[y] = b2[y-1]
				else:
					b2[y] = s
					break
				if y == 1:
					b2[0] = s
		elif b1[-2] < b2[-2] and b1[-1] > b2[0]:
			l = b1[-1]
			s = b2[0]
			for y in range(n-1):
				if b2[y+1] < l:
					b2[y] = b2[y+1]
				else:
					b2[y] = len
					break
				if y == n-2:
					b2[n-1] = l
			for y in range(n-1, 0, -1):
				if b1[y-1] > s:
					b1[y] = b1[y-1]
				else:
					b1[y] = s
					break
				if y == 1:
					b1[0] = s
	print b1, b2
	print b2[-1] + b1[-1]
else:
	print b2[-1] + b1[-1]