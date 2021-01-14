n = int(input())
s = map(int, raw_input().split())
c = 0
i = 0
max_nest = 0
max_nest_i = 0
max_l = 0
max_l_i = 0
for x in range(n):
	if s[x] == 1:
		c += 1
	else:
		c -= 1
	i += 1
	if c == 0:
		i = 0
	if c > max_nest:
		max_nest = c
		max_nest_i = x
	if i > max_l:
		max_l = i+1
		max_l_i = x-i+1
print max_nest, max_nest_i+1, max_l, max_l_i+1
