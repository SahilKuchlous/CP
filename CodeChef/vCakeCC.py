def checkIfPossible(sides2, areas2):
	for side2 in range(2):
		if areas2[0]%sides2[side2] == 0 and areas2[1]%sides2[side2] == 0:
			return 'Yes'
	return 'No'			

t = int(input())

for e in range(t):

	input = list(map(int, raw_input().strip().split()))
	r = input[0]
	c = input[1]
	m = input[2]
	k = input[3]
	j = input[4]

	output = ''

	area = r*c
	totals = m+k+j
	if area != totals or r == 0 or c == 0:
		output = 'No'
		print(output)
	else:
		sides = []
		sides.append(r)
		sides.append(c)
		areas = []
		areas.append(m)
		areas.append(k)
		areas.append(j)
		for side in range(2):
			for area in range(3):
				tempSides = sides[:]
				tempAreas = areas[:]
				if tempAreas[area] % tempSides[side] == 0:
					otherSide = tempSides.pop(side-1)
					tempSides.append(otherSide - (tempAreas[area]/tempSides[0]))
					removedArea = tempAreas.pop(area)
					output = checkIfPossible(tempSides, tempAreas)
					if output == 'Yes':
						break
			if output == 'Yes':
				break

		print(output)