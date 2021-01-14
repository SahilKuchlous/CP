from fractions import gcd

t = int(input())

for e in range(t):

	input = map(int, raw_input().strip().split(" "))
	orrA = input[0]
	orrB = input[1]
	dif = abs(orrA - orrB)
	smallest = min(orrA, orrB)
	biggest = max(orrA, orrB)
	addA = input[2]
	addB = input[3]
	hcf = gcd(addA, addB)

	smallestDif = None 
	smallestDif = abs(biggest - (smallest + hcf * round((dif * 1.0) / hcf)))

	print int(smallestDif)



