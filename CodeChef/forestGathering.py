input = map(int, raw_input().strip().split(" "))
n = input[0]
w = input[1]
l = input[2]
t = []
for x in range(n):
	t.append(map(int, raw_input().strip().split(" ")))

c = 0
m = 0
while c < w:
	c = 0
	m += 1
	for x in t:
		x[0] += x[1]
		if x[0] >= l:
			c += x[0]

print(m)