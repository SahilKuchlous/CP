# import itertools

def branches(cur_bit, carry, a1, b1, cur_a1, cur_b1, c, a_ref, b_ref):
	# print ' '*cur_bit, c, cur_a1, cur_b1, carry
	global memo
	if cur_bit == 0:
		if carry == 1 and a1 == cur_a1 and b1 == cur_b1:
			return 1
		elif carry == 0 and ((a1 == cur_a1 and b1 == cur_b1+1) or (a1 == cur_a1+1 and b1 == cur_b1)):
			return 1
		else:
			return 0
	if cur_a1 > a1:
		return 0
	if cur_b1 > b1:
		return 0
	if (cur_bit, carry, cur_a1, cur_b1) in memo:
		return memo[(cur_bit, carry, cur_a1, cur_b1)]
	else:
		o = 0
		if (c[cur_bit] == 0 and carry == 0) or (c[cur_bit] == 1 and carry == 1):
			o += branches(cur_bit-1, 0, a1, b1, cur_a1, cur_b1, c, '0'+a_ref, '0'+b_ref)
			o += branches(cur_bit-1, 1, a1, b1, cur_a1+1, cur_b1+1, c, '1'+a_ref, '1'+b_ref)
		elif (c[cur_bit] == 0 and carry == 1):
			o += branches(cur_bit-1, 1, a1, b1, cur_a1+1, cur_b1, c, '1'+a_ref, '0'+b_ref)
			o += branches(cur_bit-1, 1, a1, b1, cur_a1, cur_b1+1, c, '0'+a_ref, '1'+b_ref)
		elif (c[cur_bit] == 1 and carry == 0):
			o += branches(cur_bit-1, 0, a1, b1, cur_a1+1, cur_b1, c, '1'+a_ref, '0'+b_ref)
			o += branches(cur_bit-1, 0, a1, b1, cur_a1, cur_b1+1, c, '0'+a_ref, '1'+b_ref)
		memo[(cur_bit, carry, cur_a1, cur_b1)] = o
		return o

t = int(input())
for z in xrange(t):
	memo = {}
	a, b, c = map(int, raw_input().split())
	bin_a = bin(a)[2:]
	bin_b = bin(b)[2:]
	a1 = bin_a.count('1')
	b1 = bin_b.count('1')
	bin_c = bin(c)[2:]
	# print bin_a, bin_b, bin_c
	print(branches(len(bin_c)-1, 0, a1, b1, 0, 0, map(int, list(bin_c)), '', ''))

	'''
	min_a = int(''.join(sorted(bin_a)), 2)
	min_b = int(''.join(sorted(bin_b)), 2)
	o = 0
	k = a1-1
	flag = False
	while True:
		for x in reversed(list(itertools.combinations(range(k), a1-1))):
			bin_x = [1]+[0]*k
			for y in x:
				bin_x[y+1] = 1
			int_x = int(''.join(map(str, bin_x)), 2)
			if c - int_x < min_b:
				flag = True
				break
			d = c - int_x
			bin_d = bin(d)[2:]
			if bin_d.count('1') == b1:
				o += 1
		if flag:
			break
		k += 1
	print o
	'''
	'''
	for x in xrange(min_a, c-min_b+1):
		bin_x = bin(x)[2:]
		if bin_x.count('1') == a1:
			d = c-x
			bin_d = bin(d)[2:]
			if bin_d.count('1') == b1:
				o += 1
	print o
	'''