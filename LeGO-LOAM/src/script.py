def foo(s, e):
	for i in range(6):
		sp = (s*(6-i) + e*i) / 6.0
		ep = (s*(5-i) + e*(i+1)) / 6.0 - 1
		print(sp, ep)

foo(10, 103)
