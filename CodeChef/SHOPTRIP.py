import math

t = int(input())

for a in range(t):

	nShops, nIngredients = map(int, raw_input().split())

	coords = []
	for shop in range(nShops):
		x, y = map(int, raw_input().split())
		coords.append((x, y))

	ingredients = []
	for shop in range(nShops):
		bits = raw_input()
		ints = int(bits, 2)
		ingredients.append(ints)

	checkIngredients = reduce((lambda x, y: x|y), ingredients)
	if checkIngredients != int('1'*nIngredients, 2):
		print '-1'
		continue

	def distance(s1, s2):
		return math.sqrt(math.pow(s1[0] - s2[0], 2) + math.pow(s1[1] - s2[1], 2))

	def dp(ingredientSet, lastShop, t):
		if ingredientSet == int('1'*nIngredients, 2):
			return distance(coords[lastShop], (0, 0))
		else:
			ans = float('inf')
			for shop in range(nShops):
				d = distance(coords[shop], coords[lastShop])
				newIngredientSet = ingredientSet | ingredients[shop]
				if ingredientSet != newIngredientSet:
					ans = min(ans, d + dp(newIngredientSet, shop, t+1))
			return ans

	print min([dp(ingredients[i], i, 0) for i in range(nShops)])