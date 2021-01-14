import math
b, n = map(int, input().split())
t = int(input())
while t > 0:
	t -= 1
	pos = input()
	cur = []
	for x in range(b):
		if pos[x] == '1':
			cur.append(x)
	for i in range(1, n):
		p = math.pow(b, i)
		temp = []
		for j in range(b):
			if pos[j] == '0':
				continue
			for k in cur:
				if k%j != 0:
					continue
				val = True
				for x in str(k):
					if (j*p)%int(x) != 0:
						val = False
				if not val:
					continue
				temp.append(int(j*p+k))
		cur = []
		for j in temp:
			print(j)
			cur.append(j)
	print(len(cur))
