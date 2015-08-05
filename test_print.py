print 30000
for i in range(0,30001):
	print i
print 300000
for i in xrange(1,300001):
	if i%30000 == 0:
		print 1,1
	else:
		print i%30000,i%30000