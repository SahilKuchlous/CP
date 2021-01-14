t = int(input())

for e in range(t):

	l1 = raw_input().split(' ')
	l1 = map(int, l1)
	print(2*(l1[0]*l1[1]) - (l1[0]+l1[1]))