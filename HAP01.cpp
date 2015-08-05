#include <stdio.h>
#include <iostream>
using namespace std;
int Bits(long long i)
{
    i = i - ((i >> 1) & 0x55555555);
    i = (i & 0x33333333) + ((i >> 2) & 0x33333333);
    return (((i + (i >> 4)) & 0x0F0F0F0F) * 0x01010101) >> 24;
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		long long n,m,i,temp1,temp2;
		int k;
		scanf("%lld%lld%d",&n,&m,&k);
		int count_odd=0,count=0,count_even=0,diff;
		for(i=n;i<=m;i++)
		{
			temp1=i;
			temp2=i;
			count_odd=0;
			while(temp1)
			{
				count_odd+=(temp1 & 1);
				temp1>>=2;
			}
			count_even=Bits(i)-count_odd;
			diff=(count_odd - count_even)<0?(count_even - count_odd):(count_odd - count_even);
			if(diff==k)
				count++;
		}
		printf("%d\n",count);
	}
}