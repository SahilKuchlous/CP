n = int(input())
a = []
for x in range(n):
	a.append(int(input()))
m = 0
for x in range(len(a)):
	for y in range(x+1, len(a)):
		if a[x]&a[y] > m:
			m = a[x]&a[y]
print m