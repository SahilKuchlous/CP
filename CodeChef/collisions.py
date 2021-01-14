t = int(input())

for e in range(t):

	l1 = raw_input().split(' ')
	l1 = map(int, l1)
	numBoys = l1[0]
	numGirls = l1[1]
	girlsLiked = []
	for x in range(numGirls):
		girlsLiked.append(0)
	for x in range(numBoys):
		likedGirls = raw_input()
		for y in range(numGirls):
			if likedGirls[y] == '1':
				girlsLiked[y] = girlsLiked[y] + 1

	collisions = 0
	for x in range(numGirls):
		if girlsLiked[x] > 1:
			collisions += (girlsLiked[x]*(girlsLiked[x]-1))/2

	print(collisions)
