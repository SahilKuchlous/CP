t = int(input())
for z in range(t):
	n, m = map(int, raw_input().split())
	a = map(int, raw_input().split())
	b = set(map(int, raw_input().split()))
	print len([x for x in a if x in b])