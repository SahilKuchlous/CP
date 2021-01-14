t = int(input())
for z in range(t):
	n, m = map(int, raw_input().split())
	a = [x for x in map(int, raw_input().split()) if x != 0]
	b = [x for x in map(int, raw_input().split()) if x != 0]
	a = sorted(a, reverse = True)
	b = sorted(b, reverse = True)
	if a == b:
		print 'Bob'
		continue
	print 'Alice'