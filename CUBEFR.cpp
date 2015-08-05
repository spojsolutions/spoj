#include<stdio.h>
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
int A[1000001]={0};
void cube_free()
{
	int i,k,j;
	for(i=2;i<=100;i++)
	{
		if(A[i]==0)
		{
			k=i*i*i;
			for(j=k;j<=1000000;j+=k)
				A[j]=-1;
		}
	}
	k=1;
	for(i=1;i<=1000000;i++)
		if(A[i]==0)
			A[i]=k++;
}
int main()
{
	cube_free();
	int t,n;
	scanint(t);
	for(int i=1;i<=t;i++)
	{
		scanint(n);
		if(A[n] != -1)
			printf("Case %d: %d\n",n,A[n] );
		else
			printf("Case %d: Not Cube Free\n",n);
	}
	return 0;
}