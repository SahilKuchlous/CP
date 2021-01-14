t = int(input())
for x in range(t):
	n, m, a, b = map(int, raw_input().split())
	total = 0
	for x in range(1, n+1):
		for y in range(1, m+1):
			# print x, y, m*n-1, m+n, min(x-1, y-1) + min(n-x, y-1) + min(x-1, m-y) + min(n-x, m-y), m*n-1-(m+n-2+min(x-1, y-1) + min(n-x, y-1) + min(x-1, m-y) + min(n-x, m-y))
			if not (x == a and y == b):
				pos = m*n-1
				pos -= m+n-2
				pos -= min(x-1, y-1) + min(n-x, y-1) + min(x-1, m-y) + min(n-x, m-y)
				total += pos
			else:
				pos = m*n-1
				pos -= m+n-2
				pos -= min(x-1, y-1) + min(n-x, y-1) + min(x-1, m-y) + min(n-x, m-y)
				total -= pos
	# print total
	# print (a-1)*(n-a)*2, (b-1)*(m-b)*2, min(a-1, b-1)*min(n-a, m-b)*2, min(n-a, y-1)*min(x-1, m-b)*2
	total += (a-1)*(n-a)*2
	total += (b-1)*(m-b)*2
	total += min(a-1, b-1)*min(n-a, m-b)*2
	total += min(n-a, b-1)*min(a-1, m-b)*2
	print total