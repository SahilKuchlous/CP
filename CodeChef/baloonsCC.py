t = int(input())

for e in range(t):

	str = raw_input()

	no_a = 0
	no_b = 0
	for x in str:
		if x == 'a':
			no_a += 1
		elif x == 'b':
			no_b += 1

	minFlips = 0
	if no_a > no_b:
		minFlips = no_b
	elif no_b > no_a:
		minFlips = no_a

	print(minFlips)
		
