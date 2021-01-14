t = int(input())

for e in range(t):
	n = int(input())
	chocolates = raw_input().strip().split(" ")

	# Sequence is working
	sequence = []
	for x in range(len(chocolates) - 2):
		if int(chocolates[x]) + int(chocolates[x+1]) == int(chocolates[x+2]):
			sequence.append(1)
		else:
			sequence.append(0)

	inSequence = 0
	gSequence = 0
	end = 0
	for x in range(len(sequence)):
		if sequence[x] == 1:
			inSequence += 1
			if x == len(sequence) - 1:
				end = x + 1
				gSequence = inSequence
		else:
			if inSequence > gSequence:
				gSequence = inSequence
				end = x
			inSequence = 0

	space = " "
	output = chocolates[end - gSequence:end + 2]
	print(len(output))