#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
#define gc getchar_unlocked
inline void scanint(int &x)
{
    register int c = gc();
    x = 0;
    int neg = 0;
    for(;((c<48 || c>57) && c != '-');c = gc());
    if(c=='-') {neg=1;c=gc();}
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
    if(neg) x=-x;
}
void heapify(int *a, int root, int bottom);
inline void hsort(int *a, int size) {
	register int i;
	int temp;
	for(i = size / 2; i >= 0; i--)
		heapify(a, i, size - 1);

	for(i = size - 1; i >= 1; i--) {
		temp = a[0];
		a[0] = a[i];
		a[i] = temp;
		heapify(a, 0, i - 1);
	}
}

inline void heapify(int *a, int root, int bottom) {
	register int maxChild = root * 2 + 1;
	if(maxChild < bottom) {
		int otherChild = maxChild + 1;
		maxChild = (a[otherChild] > a[maxChild]) ? otherChild : maxChild;
	}
	else if(maxChild > bottom)
		return;

	if(a[root] >= a[maxChild])
		return;

	int temp = a[root];
	a[root] = a[maxChild];
	a[maxChild] = temp;

	heapify(a, maxChild, bottom);
}
int main()
{
	int t,i;
	scanint(t);
	int A[t];
	for(i=0;i<t;i++)
		scanint(A[i]);
	hsort(A,t);
	for(i=0;i<t;i++)
		printf("%d\n",A[i]);
	return 0;
}
