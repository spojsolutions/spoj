#include<stdio.h>
int main()
{
	int A[10],i,sum=0,d1,d2;
	for(i=0;i<10;i++)
	{
		scanf("%d",&A[i]);
	}
	i=0;
	while((sum<100)&&(i<10))
	{
		sum=sum+A[i];
		i++;
	}
	if(i==10)
		printf("%d\n",sum);
	else
	{
		d1=100-(sum-A[i-1]);
		d2=sum-100;
		if(d1==d2||(d2<d1))
			printf("%d\n",sum);
		else if(d1<d2)
			printf("%d\n",sum-A[i-1]);
	}
	return 0;
}