t = int(input())

for a in range(t):

	n, k, x, m, s = map(int, raw_input().split())

	s -= 1

	paths = []
	for c in range(n):
		paths.append([])

	for c1 in range(k):
		for c2 in range(k):
			if c1 != c2:
				paths[c1].append((c2, x))

	for p in range(m):
		ai, bi, ci = map(int, raw_input().split())
		ai -= 1
		bi -= 1
		paths[ai].append((bi, ci))
		paths[bi].append((ai, ci))

	sptSet = {}
	distances = []
	unchecked = set()

	for c in range(n):
		distances.append(float('inf'))
		unchecked.add(c)
	distances[s] = 0

	while len(sptSet) < n:
		closest = min(unchecked, key = lambda x: distances[x])
		unchecked.remove(closest)
		d = distances[closest]
		sptSet[closest] = d
		for path in paths[closest]:
			destination, distance = path[0], path[1]
			if (d + distance) < distances[destination]:
				distances[destination] = (d + distance)

	print ' '.join(map(str, [sptSet[c] for c in sptSet]))