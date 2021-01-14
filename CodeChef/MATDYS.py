q = int(input())
for x in range(q):
	n, p = map(int, raw_input().split())
	a = format(p, '0'+`n`+'b')
	a = a[::-1]
	print int(a, 2)