t = int(input())
for z in range(t):
	s = raw_input()
	n = 0
	for x in range(len(s)):
		ss = s[x:]+s[:x]
		if ss == ss[::-1]:
			n += 1
	print n