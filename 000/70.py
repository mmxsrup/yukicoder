n = input()

sum = 0
for i in range(0, n):
	d1, d2 = raw_input().split()
	h1, m1 = map(int, d1.split(':'))
	h2, m2 = map(int, d2.split(':'))
	if h1 > h2 or (h1 == h2 and m1 > m2):
		time1 = h1 * 60 + m1
		time2 = (h2 + 24) * 60 + m2
		sum += time2 - time1
	else:
		time1 = h1 * 60 + m1
		time2 = h2 * 60 + m2
		sum += time2 - time1

print sum
