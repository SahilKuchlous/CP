import math
t = int(input())

sells = []
for x in range(101):
	d = {}
	d['-1'] = {'-1': 0}
	for y in range(1, 11):
		d[str(y)] = {'-1': 0}
		for z in range(1, 5):
			d[str(y) + '.' + str(z)] = {'-1': 0}
	sells.append(d)

for a in range(t):
	
	inp = raw_input().split()
	
	if inp[0] == 'S':
		
		sale = inp[1:]
		d = int(sale[0])
		sells[d][sale[1]][sale[2]] = sells[d][sale[1]].get(sale[2], 0) + 1
		sells[d]['-1'][sale[2]] = sells[d]['-1'].get(sale[2], 0) + 1
		sells[d][sale[1]]['-1'] += 1
		sells[d]['-1']['-1'] += 1
		if float(sale[1]) != int(math.floor(float(sale[1]))):
			sells[d][`int(math.floor(float(sale[1])))`][sale[2]] = sells[d][`int(math.floor(float(sale[1])))`].get(sale[2], 0) + 1
			sells[d][`int(math.floor(float(sale[1])))`]['-1'] += 1
		if float(sale[2]) != int(math.floor(float(sale[2]))):
			sells[d][sale[1]][`int(math.floor(float(sale[2])))`] = sells[d][sale[1]].get(`int(math.floor(float(sale[2])))`, 0) + 1
			sells[d]['-1'][`int(math.floor(float(sale[2])))`] = sells[d]['-1'].get(`int(math.floor(float(sale[2])))`, 0) + 1
		if float(sale[1]) != int(math.floor(float(sale[1]))) and float(sale[2]) != int(math.floor(float(sale[2]))):
			sells[d][`int(math.floor(float(sale[1])))`][`int(math.floor(float(sale[2])))`] = sells[d][`int(math.floor(float(sale[1])))`].get(`int(math.floor(float(sale[2])))`, 0) + 1
	
	else:
		
		query = inp[1:]
		if float(query[0]) == int(math.floor(float(query[0]))):
			d = int(query[0])
			print sells[d][query[1]].get(query[2], 0)
		else:
			d = map(int, query[0].split('.'))
			s = 0
			for x in range(d[0], d[1]+1):
				s += sells[x][query[1]].get(query[2], 0)
			print s