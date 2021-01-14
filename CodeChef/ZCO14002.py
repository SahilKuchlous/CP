n = int(input())
a = map(int, raw_input().split())
if n>3:
	best = [0]*n
	best[0] = a[0]
	best[1] = a[1]
	best[2] = a[2]
	for x in range(3, n):
		best[x] = min(best[x-1], best[x-2], best[x-3]) + a[x]
	print min(best[n-1], best[n-2], best[n-3])
else:
	print min(a)