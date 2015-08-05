#include <stdio.h>
#include <cstdlib>
int gcd(int a,int b)
{
	if(a==0)
		return b;
	return gcd(b%a,a);
}
int main()
{
	int k,num,count=0,first,i,flage=1;
	for(k=3;k<=202;k++)
	{
		flage=1;
		num=k*495;
		if(k<=20)
		{
			int *dig;
			dig=(int *)calloc(10,sizeof(int));
			while(num!=0 )
			{
				if(num%10==0 || dig[num%10]==1)
				{
					flage=0;
					break;
				}
				dig[num%10]=1;
				num/=10;
			}
			if(flage)
				count++;
		}
		else{
			int *dig;
				dig=(int *)calloc(10,sizeof(int));
			while(num!=0)
			{
				if(dig[num%10]==1)
				{
					flage=0;
					break;
				}
				dig[num%10]=1;
				num/=10;
			}
			if(flage)
				count++;
		}
	}
	int temp=gcd(count,30240)
	printf("%d/%d",count/temp,30240/temp);
	return 0;
}