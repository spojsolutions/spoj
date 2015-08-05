#include<stdio.h>
#include<iostream>
using namespace std;
#define gc getchar_unlocked
inline void scanint(long &x)
{
    register long c = gc();
    x = 0;
    long neg = 0;
    for(;((c<48 || c>57) && c != '-');c = gc());
    if(c=='-') {neg=1;c=gc();}
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
    if(neg) x=-x;
}
int main()
{
	long t;
	scanint(t);
	int result[7]={-4,-3,-2,-4,-4,-3,-4};
	while(t--)
	{
		long N;
		scanint(N);
		int i;
		long temp;
		for(i=0;i<N;i++){
			scanint(temp);
			if(temp>=0)
			{
				if(temp>6)
					printf("-4 ");
				else
					printf("%d ",result[temp]);
			}
			else
				printf("%ld ",temp);
		}
		printf("\n");
	}
	return
}