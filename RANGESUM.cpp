#include <stdio.h>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
int main()
{
	int n;
	scanf("%d",&n);

	long long sum[200000],temp;
	int i,j,k;
	sum[0]=0;
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&temp);
		sum[i]+=temp+sum[i-1];
	}
	int q,c,l,r,u,s=0,f=0;
	scanf("%d",&q);
	while(q--)
	{
		scanf("%d",&c);
		if(c==1)
		{
			scanf("%d%d",&l,&u);
			printf("%lld\n",sum[u]-sum[l-1]);
		}
		else if(c==2)
		{
			scanf("%d",&u);
			n++;
			long long temp,temp1,temp2;
			temp1=sum[1];
			sum[1]=u;
			
		}
	}
	return 0;
}