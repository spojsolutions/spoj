import sys
arr = []
arr.append(0)
arr.append(4)
def pre():
    arr1 = []; arr3 = []; arr5 = []; arr7 = [];
    arr1.append(0), arr3.append(0), arr5.append(0), arr7.append(0)
    arr1.append(1), arr3.append(1), arr5.append(1), arr7.append(1)
    for i in range(2,10001):
        arr1.append(arr3[i-1])
        arr3.append(arr1[i-1] + arr7[i-1])
        arr5.append(arr3[i-1] + arr7[i-1])
        arr7.append(arr5[i-1])
        arr.append(arr1[i] + arr3[i] + arr5[i] + arr7[i])

t = int(sys.stdin.readline())
pre()
while t:
    n = int(sys.stdin.readline())
    print arr[n]
    t = t-1;