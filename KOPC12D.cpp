#include <stdio.h>
#include <iostream>
using namespace std;
int main()
{
	int t,a[15],i,j,k,count;
	scanf("%d",&t);
	while(t--)
	{
		int r[300]={0},check[300]={0},mul=0,temp[15];
		for(i=2;i<=9;i++)
		{
			scanf("%d",&a[i]);
			temp[i]=a[i];
			mul+=a[i];
		}
		if(mul==0){
			printf("1\n");
			continue;
		}
		for(i=2;i<=9;i++)
		{
			for(j=1;j<=mul;j++)
			{
				if(a[i]!=0){
					if(j%i!=0 && check[j]==0){
						r[j]=i;
						a[i]--;
						check[j]=1;
					}
				}
			}
			count+=a[i];
		}
		for(i=1;i<=mul;i++)
		{
			for(j=2;j<=9;j++)
			{
				if(r[i]==0){
					if(i%j!=0 && temp[j]!=0)
					{
						count--;
						temp[j]--;
						r[i]=-1;
					}
				}
			}
		}
		printf("%d\n",mul+count);
	}
	return 0;
}