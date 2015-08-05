#include<stdio.h>
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int num,i=0,count=0;
		scanf("%d",&num);
		while(num!=0)
		{
			if(num%2==1)
				count++;
			num/=2;
		}
		printf("%d\n",count);
	}
	return 0;
}