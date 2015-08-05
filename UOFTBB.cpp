#include <stdio.h>
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
int main()
{
	int t;
	scanint(t);
	while(t--)
	{
		int n,l,upper_limit,lower_limit;
		long a[100000]={0};
		scanint(l);
		scanint(n);
		int i,c,r,d,j;
		for(i=1;i<=n;i++)
		{
			scanint(c);
			scanint(r);
			scanint(d);
			lower_limit=(c-r)<1?1:(c-r);
			upper_limit=(c+r)>l?l:(c+r);
			for(j=lower_limit;j<=upper_limit;j++)
				a[j]+=d;
		}
		int m,h,flag,pos;
		scanint(m);
		for(i=1;i<=m;i++)
		{
			scanint(h);
			flag=1;
			for(j=1;j<=l;j++)
			{
				h-=a[j];
				if(h<=0)
				{
					flag=0;
					pos=j;
					break;
				}
			}
			if(flag)
				printf("Bloon leakage\n");
			else
				printf("%d\n",pos);
		}
	}
	return 0;
}