t = int(input())

for e in range(t):

	str = raw_input()

	dict = {}

	for x in range(len(str)):
		if str[x] in dict:
			dict[str[x]] = -1
		else:
			dict[str[x]] = x

	shankyIndex = len(str)
	ankuIndex = -1
	for x in dict:
		if dict[x] != -1:
			if dict[x] < shankyIndex:
				shankyIndex = dict[x]
			if dict[x] > ankuIndex:
				ankuIndex = dict[x]

	ankuLetter = 0
	shankyLetter = 0

	if ankuIndex != -1:
		ankuLetter = str[ankuIndex]
	else:
		print('PANDEY')
		continue

	if shankyIndex != len(str):
		shankyLetter = str[shankyIndex]
	else:
		print('PANDEY')
		continue

	if shankyLetter > ankuLetter:
		print('SHANKY')
	elif ankuLetter > shankyLetter:
		print('ANKU')
	else:
		print('PANDEY')