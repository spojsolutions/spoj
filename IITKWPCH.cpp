#include <stdio.h>
#include <iostream>
#include <cstdlib>
#define LL long long
using namespace std;
#define gc getchar_unlocked
inline void scanint(LL &x)
{
    register LL c = gc();
    x = 0;
    LL neg = 0;
    for(;((c<48 || c>57) && c != '-');c = gc());
    if(c=='-') {neg=1;c=gc();}
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
    if(neg) x=-x;
}
int main()
{int n,i,j,num=0;
		scanf("%d",&n);
		LL temp,total=0;
		LL *a=(LL *)calloc(1200,sizeof(LL));
		int dig[10]={0};
		while(n--)
		{
			scanint(temp);
			while(temp)
			{
				num=num | (1<<temp%10);
				temp/=10;
			}
			a[num]++;
			num=0;
		}
		for(i=1;i<1024;i++)
		{
			for(j=1;j<1024;j++)
			{
				if(i!=j && (i&j)){
					total+=a[i]*a[j];
				}
			}
		}
		for(i=1;i<1024;i++)
			total+=(a[i]*(a[i]-1));
		printf("%lld\n",total/2);
	return 0;
}