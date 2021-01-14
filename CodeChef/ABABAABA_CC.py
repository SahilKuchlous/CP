# Input for number of tests
t = int(input())

for n in range(t):
	
	s = raw_input()

	A_no = 0
	B_no = 0
	for x in range(len(t)):
		if t[x-1] == 'A':
			A_no += 1
		elif t[x-1] == 'B':
			B_no += 1

	if A_no == 2:
		print('A')
	elif B_no == 2:
		print('B')
	else:
		print('-1')
