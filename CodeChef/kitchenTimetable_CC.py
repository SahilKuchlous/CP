t = int(input())

for n in range(t):
	
	num_students = int(input())
	timings = map(int, raw_input().strip().split(" "))
	timeTaken = map(int, raw_input().strip().split(" "))

	num_completions = 0
	for x in range(num_students):
		if timings[x] - timings[x-1] >= timeTaken[x] and x != 0:
			num_completions += 1
		elif x == 0 and timings[x] >= timeTaken[x]:
			num_completions += 1

	print num_completions


