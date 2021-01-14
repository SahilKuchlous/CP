t = int(input())

for z in range(t):

	s1 = map(int, raw_input().split())
	s2 = map(int, raw_input().split())
	x1 = False
	x2 = False
	c1 = False
	c2 = False
	if s1[0] == s1[2]:
		x1 = True
	if s2[0] == s2[2]:
		x2 = True
	if (s1[0], s1[1]) == (s1[2], s1[3]):
		c1 = True
	if (s2[0], s2[1]) == (s2[2], s2[3]):
		c2 = True

	if c1 and c2:

		if (s1[0], s1[1]) == (s2[0], s2[1]):
			print 'yes'
			continue
		else:
			print 'no'
			continue

	if c1:

		if x2:
			ssort = sorted([s1, s2], key = lambda x: abs(x[1] - x[3]))
			ss = ssort[0]
			sl = ssort[1]
			if sl[0] == ss[0]:
				if sl[1] <= ss[1] <= sl[3] or sl[1] >= ss[1] >= sl[3]:
					print 'yes'
					continue
				else:
					print 'no'
					continue
			else:
				print 'no'
				continue

		else:
			ssort = sorted([s1, s2], key = lambda x: abs(x[0] - x[2]))
			ss = ssort[0]
			sl = ssort[1]
			if sl[1] == ss[1]:
				if sl[0] <= ss[0] <= sl[2] or sl[0] >= ss[0] >= sl[2]:
					print 'yes'
					continue
				else:
					print 'no'
					continue
			else:
				print 'no'
				continue

	if c2:

		if x1:
			ssort = sorted([s1, s2], key = lambda x: abs(x[1] - x[3]))
			ss = ssort[0]
			sl = ssort[1]
			if sl[0] == ss[0]:
				if sl[1] <= ss[1] <= sl[3] or sl[1] >= ss[1] >= sl[3]:
					print 'yes'
					continue
				else:
					print 'no'
					continue
			else:
				print 'no'
				continue

		else:
			ssort = sorted([s1, s2], key = lambda x: abs(x[0] - x[2]))
			ss = ssort[0]
			sl = ssort[1]
			if sl[1] == ss[1]:
				if sl[0] <= ss[0] <= sl[2] or sl[0] >= ss[0] >= sl[2]:
					print 'yes'
					continue
				else:
					print 'no'
					continue
			else:
				print 'no'
				continue

	if x1 and x2:
		
		ssort = sorted([s1, s2], key = lambda x: abs(x[1] - x[3]))
		ss = ssort[0]
		sl = ssort[1]
		if sl[0] == ss[0]:
			if sl[1] <= ss[1] <= sl[3] or sl[1] >= ss[1] >= sl[3] or sl[1] <= ss[3] <= sl[3] or sl[1] >= ss[3] >= sl[3]:
				print 'yes'
				continue
			else:
				print 'no'
				continue
		else:
				print 'no'
				continue

	if not x1 and not x2:

		ssort = sorted([s1, s2], key = lambda x: abs(x[0] - x[2]))
		ss = ssort[0]
		sl = ssort[1]
		if sl[1] == ss[1]:
			if sl[0] <= ss[0] <= sl[2] or sl[0] >= ss[0] >= sl[2] or sl[0] <= ss[2] <= sl[2] or sl[0] >= ss[2] >= sl[2]:
				print 'yes'
				continue
			else:
				print 'no'
				continue
		else:
				print 'no'
				continue

	if (s1[0], s1[1]) == (s2[0], s2[1]) or (s1[0], s1[1]) == (s2[2], s2[3]) or (s1[2], s1[3]) == (s2[0], s2[1]) or (s1[2], s1[3]) == (s2[2], s2[3]):
		print 'yes'
		continue
	else:
		print 'no'
		continue