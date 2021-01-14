t = int(input())

for x in range(t):

	a, b = map(int, raw_input().split())

	if (a%2 == b%2 and abs(a-b) == 2) or (min(a, b) % 2 == 1 and max(a, b) % 2 == 0 and abs(a-b) == 1):
		print 'YES'
	else:
		print 'NO'

