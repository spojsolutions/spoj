from random import randint

print 1
print 100000
a=[]
seed = randint(1, 100)
a = [seed]
for i in range(1, 100000):
	s = randint(0,1)
	if s == 0:
		si = 1
	else:
		si = -1
	a.append(a[-1] + si*(randint(0,50)))

for i in a:
	print i,