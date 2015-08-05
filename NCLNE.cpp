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
	int t,i,flage;
	long max=1,temp,n;
	scanf("%d",&t);
	while(t--)
	{
		flage=1;
		max=1;
		scanint(n);
		for(i=0;i<n;i++){
			scanf("%ld",&temp);
			if(i==n-1 && max!=temp)
				flage=0;
			else if(temp<=max){
				max=max-temp;
				max=2*max;
			}
			else if(temp>max)
				flage=0;
		}
		if(flage)
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}