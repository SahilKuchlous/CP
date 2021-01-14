t = int(input())
for z in range(t):
	n = int(input())
	a = map(int, raw_input().split())
	for x in range(n):
		a[x] = (a[x], x)
	b = []
	for x in range(n):
		b.append('0')
	flag = False
	flag2 = 0
	y = 1
	while True:
		ac = a[:]
		flag2 = 0
		for x in range(1, len(a)-1):
			if a[x][0] < a[x-1][0] and a[x][0] < a[x+1][0]:
				b[a[x][1]] = str(y)
				ac.pop(x-flag2)
				flag2 += 1
			elif x == len(a)-2 and flag2 == 0:
				flag = True
		if flag:
			break
		a = ac[:]
		y += 1
	print ' '.join(b)
