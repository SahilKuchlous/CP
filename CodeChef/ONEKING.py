t = int(input())
for a in range(t):
	n = int(input())
	k = []
	o = 0
	for x in range(n):
		k.append(map(int, raw_input().split()))
	for x in range(len(k)):
		for y in range(x+1, len(k)):
			print k[x], k[y]
			print k[y][0], k[x][1], k[y][1]
			if k[y][0] <= k[x][0] <= k[y][1] or k[y][0] <= k[x][1] <= k[y][1]:
				o += 1
	print len(k) - o