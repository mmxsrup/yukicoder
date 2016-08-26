n = input()

ans = 0
for x in range(1, n + 1):
	now = -(x * x) + (x * n) + n
	ans = max(ans, now)
print ans