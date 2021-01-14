t = int(input())
for z in range(t):
	n, x = map(int, raw_input().split())
	a = map(int, raw_input().split())
	print 'YES' if len([i for i in a if i >= x]) > 0 else 'NO'