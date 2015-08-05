#include <iostream>
#include <stdio.h>
using namespace std;
/*void prime()
{
	int i,j,k;
	for(i=2;i*i<=5500;i++)
	{
		if(a[i]==0)
		{
			for(j=i*i;j<=5500;j+=i)
				a[j]=1;
		}
	}
	for(j=2;j<=5500;j++)
		if(a[j]==0){
			p[k++]=j;
		}
}*/
int main()
{
	int i,j,k=0;
	int a[5510]={0};
	int p[5510];
	for(i=2;i*i<=5500;i++)
	{
		if(a[i]==0)
		{
			for(j=i*i;j<=5500;j+=i)
				a[j]=1;
		}
	}
	for(j=2;j<=5500;j++)
		if(a[j]==0){
			p[k++]=j;
		}
	int t;
	scanf("%d",&t);
	while(t--)
	{
		long n,dig=9,temp,d;
		scanf("%ld",&n);
		temp=n/10;
		while(temp)
		{
			temp/=10;
			dig=dig*10 + 9;
		}
		d=dig- 2*n;
		if(d<0)
			d=-1*d;
		if(d==1)
			printf("-1\n");
		else
		{
			for(j=0;j<=k-1;j++){
				if(d%p[j]==0)
				{
					printf("%d\n",p[j]);
					break;
				}
			}
			if(j>=k)
				printf("%ld\n",d);
		}
	}
	return 0;
}