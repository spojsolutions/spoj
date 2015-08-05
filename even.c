#include<stdio.h>
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		long int n,temp,sum=0;
		scanf("%ld",&n);
		temp=n;
		int i=0,count=0,rem[64];
		while(temp!=0)
		{
			rem[i]=temp%2;
			i++;
			temp=temp/2;
		}
		count=i;
		for(i=0;i>=0;i--)
		{
			sum=sum+pow(2,i);
		}
		printf("%ld\n",sum);
	}
	return 0;
}