#include <iostream>
#include <cstdlib>
#include <cmath>
#include<stdio.h>
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
	int *list=(int*)calloc(1001,sizeof (int));
	list[1]=1;
	list[2]=2;
	list[3]=3;
	int i,max,j;
	for (i=4; i<=1000; i++)
	{
		max=1000000;
		if ((int)sqrt(i)==sqrt(i))
		{
			list[i]=1;
		}
		else
		{
			for (j=1; j<=i/2; j++)
			{
				if (list[j]+list[i-j] < max)
					max=list[j]+list[i-j];
			}
			list[i]=max;
		}
	}
	int t,n;
	scanint(t);
	while(t--)
	{
		scanint(n);
		printf("%d\n",list[n]);
	}
	return 0;
}