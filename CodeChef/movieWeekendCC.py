t = int(input())

for e in range(t):

	n = int(input())
	l_str = raw_input()
	r_str = raw_input()

	l_str = l_str.strip().split(" ")
	r_str = r_str.strip().split(" ")

	lr_str = []
	for x in range(n):
		lr_str.append(int(l_str[x]) * int(r_str[x]))

	lr_max = 0
	maxIndex = 0
	for x in range(n):
		if int(lr_str[x]) > lr_max:
			lr_max = lr_str[x]
			maxIndex = x

	max_r = 0
	for x in range(n):
		if int(lr_str[x]) == lr_max:
			if int(r_str[x]) > max_r:
				max_r = int(r_str[x])
				maxIndex = x

	max_i = 0
	for x in range(n):
		if int(lr_str[x]) == lr_max:
			if int(r_str[x]) == max_r:
				print(x + 1)
				break