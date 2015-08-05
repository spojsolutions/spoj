#include<stdio.h>
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		long int A,B,num,de,rem=1;
		scanf("%ld%ld",&A,&B);
		if(A>B)
		{
			num=A;
			de=B;
		}
		else
		{
			num=B;
			de=A;
		}
		while(rem!=0)
		{

			rem=num%de;
			num=de;
			de=rem;
		}
		printf("%ld %ld",B/num,A/num);
		printf("\n");
	}
	return 0;
}