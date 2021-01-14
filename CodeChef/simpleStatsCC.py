# Input for number of tests
t = int(input())

for n in range(t):
	
	l1 = raw_input().strip().split(" ")
	n_m = int(l1[0])
	n_d = int(l1[1])
	old_e = raw_input().strip().split(" ")
	e = []

	for x in old_e:
		e.append(int(x))

	e.sort()

	print(e)

	for x in range(n_d):
		e.pop(0)
		e.pop()

	print(e)

	sum = 0
	for x in e:
		sum += int(x)
	print(sum)

	average = sum / len(e)
	print(average)

		