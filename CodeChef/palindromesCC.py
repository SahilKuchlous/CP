t = int(input())

for e in range(t):
	
	numPalindromes = int(input())
	letter = 0
	word = []
	for x in range(numPalindromes):
		if letter == 0:
			word.append('a')
			letter += 1
		elif letter == 1:
			word.append('b')
			letter += 1
		elif letter == 2:
			word.append('c')
			letter = 0

	print(''.join(word))


