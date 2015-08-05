#include<stdio.h>
int main()
{
	unsigned long long N,sum=0,temp,count=0;
	int rem;
	scanf("%llu",&N);
	temp=N;
	while(sum!=1 && sum!=2 && sum!=3 && sum!=4 && sum!=5 && sum!= 6 && sum!=8 && sum!=9)
	{
		sum=0;
		while(temp!=0)
		{
			rem=temp%10;
			sum=sum+(rem*rem);
			printf("%llu\n",sum);
			temp=temp/10;
		}
		temp=sum;
		count++;
	}
	if(sum==1)
		printf("%llu\n",count);
	else
		printf("-1\n");
	return 0;
}