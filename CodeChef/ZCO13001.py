n = int(input())
a = map(int, raw_input().split())
a = sorted(a)
s = 0
for x in range(n-1):
	s += (n-(x+1))*(x+1)*(a[x+1] - a[x])
print s