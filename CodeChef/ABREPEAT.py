t = int(input())

for z in range(t):
	n, k = map(int, raw_input().split())
	s = raw_input()
	ac = 0
	bc = 0
	ans = 0
	f = (k*(k+1))/2
	for x in s[::-1]:
		if x == 'b':
			bc += 1
			ans += ac*(f-k)
		elif x == 'a':
			ac += 1
			ans += bc*f
	print ans