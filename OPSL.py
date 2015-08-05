import sys , math
def hcf(x , y):
	result = 0
	while x%y != 0 :
		result = x%y 
		x = y
		y = result
	return y;
def lcm(x , y):
	return (x*y // hcf(x , y))
t  = int(sys.stdin.readline())
for test in xrange(1,t+1):
	pass
	n = int(sys.stdin.readline())
	a = []
	a = map(int , sys.stdin.readline().split())
	res = a[0];
	for i in range(1,n):
		res = lcm(res , a[i])
	res = res%1000000007
	s = ""
	s = s + "Case " + str(test) + ": " + str(res)
	print s