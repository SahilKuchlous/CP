t = int(input())

for z in range(t):
	s = raw_input()
	seq = 1
	lSeq = 1
	cur = s[0]
	if '<' not in s and '>' not in s:
		print 1
	else:
		for x in s[1:]:
			if x != '=':
				if x == cur:
					seq += 1
					if seq>lSeq:
						lSeq = seq
				else:
					seq = 1
					cur = x

		print lSeq+1