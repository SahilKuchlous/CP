n = int(input())
b = map(int, raw_input().split())
d = 0
ad = 0
lb = 0
for x in b:
	if x == 1 or x == 3:
		d += 1
	else:
		d -= 1
	if lb == 1 and x == 3:
		ad += 1
		lb = 3
	elif lb = 1 and x == 3:
		ad += 1
		lb += 3