from os import system, uname
from random import randint

magic = "HAPPY NEW YEAR 2015"
ll = len(magic)
itr = 10**7
tup = uname()
cmd = "clear"
if (tup[0] != "Linux"):
	cmd = "cls"
while True:
	system(cmd)
	p = randint(0, 1<<ll)
	for i in range(0, ll):
		if p & (1<<i):
			print magic[i],
		else:
			print " ",
	print
 