#include<stdio.h>
#include<stdlib.h>
#include<iostream>
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
int main()
{
	int N;
	scanint(N);
	int A[N],i,j,num1,num2,temp,count;
	long long sum,total=0;
	for(i=0;i<N;i++)
		scanint(A[i]);
	for(i=0;i<N;i++)
	{
		for(j=i+1;j<N;j++)
		{
			num1=A[i];
			num2=A[j];
			sum=num1 ^ num2;
			total+=sum;
		}
	}
	printf("%lld\n",total);
	return 0;
}