t = int(input())

for e in range(t):

	nSubarrays = int(input())
	binSubarrays = bin(nSubarrays)
	binSubarrays = binSubarrays[2:]
	subarrayLen = len(binSubarrays)

	curNo = 99
	array = []
	for x in binSubarrays:
		if x == 0:
			continue
		else:
			for y in range(subarrayLen):
				for z in range(2):
					array.insert(-y, curNo)
					curNo -= 1

			
		
