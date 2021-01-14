import math

t = int(input())

for e in range(t):

	l1 = raw_input().strip().split(" ")
	n1 = int(l1[0])
	n2 = int(l1[1])

	total = 0
	for i in range(n1,n2+1):
		
		f = []
		for x in range(1,int(math.ceil(math.sqrt(i)))+1):
			if i%x == 0:
				f.append(int(x))
				if i%x != x:
					f.append(int(i/x))

		fSum = 0
		for x in f:
			if x%2 == 1:
				fSum += x			

		total += fSum

	print(total)