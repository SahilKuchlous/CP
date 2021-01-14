t = int(input())

for e in range(t):

	l1 = raw_input().split(' ')
	l1 = list(map(int, l1))
	n = l1[0]
	k = l1[1]
	e = l1[2]
	m = l1[3]

	scores = []
	for x in range(n):
		inputScore = raw_input().split(' ')
		inputScore = list(map(int, inputScore))
		score = 0
		for y in inputScore:
			score += y
		scores.append(score)

	sergeyScore = scores.pop(-1)
	scores.sort()
	minimumScore = scores[(n-(n-k))-1]+1
	if minimumScore<0:
		minimumScore = 0
	print(minimumScore - sergeyScore)