n = int(raw_input())
d = 1234567891011121314151617181920212223242526272829303132333435363738394041424344454647484950515253545556575859606162636465666768697071727374757677787980818283848586878889909192939495969798991
ans = d * n
s = str(ans)

if n <= 8:
	ss = "0." + s
	print ss
elif 9 <= n and n <= 81:
	ss = s[0] + '.'
	for i in range(1,len(s)):
		ss += s[i]
	print ss
else:
	ss = s[0] + s[1] + '.'
	for i in range(2,len(s)):
		ss += s[i]
	print ss