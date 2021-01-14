import fractions
import sets
import copy

def findArrays (n, m, coArray):

	nArrays = 0
	
	if n == 1:
		nArrays = m
		return nArrays

	if n == 2:
	 	for x in range(len(coArray)):
	 	 	nArrays += len(coArray[x]) 
	 	return nArrays
	
	combosArray = []
	for x in range(len(coArray)):
		combosArray.append([])
		for y in coArray[x]:
			combosArray[x].append([y])
			

	newCombosArray = []
	for arraySize in range(3, n+1):
		for combosNum in range(len(combosArray)):
			newCombosArray.append([])
			for combo in combosArray[combosNum]:
				intersection = copy.copy(coArray[combosNum])
				for coprime in combo:
					intersection.intersection_update(coArray[coprime - 1])
				for newCoprime in intersection:
					newCombosArray[combosNum].append(combo + [newCoprime])
		combosArray = newCombosArray
		newCombosArray = []

	for combos in combosArray:
	 	nArrays += len(combos) 
	return nArrays
	

t = int(input())

for e in range(t):
	
	input = map(int, raw_input().strip().split(" "))
	n = input[0]
	m = input[1]

	coprimes = []
	for n1 in range(1, m+1):
		coprimes.append(sets.Set([]))
		for n2 in range(1, m+1):
			if fractions.gcd(n1, n2) == 1:
				coprimes[n1-1].add(n2)

	output = findArrays(n, m, coprimes)

	print(output)


					

