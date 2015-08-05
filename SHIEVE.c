#include<stdio.h>
unsigned short A[100000001];
int main()
{
	long long i,j,count=0,T=0;
	for(i=0;i<=100000000;i++)
		A[i]=1;
	for(i=2;i<=100000000;i++)
	{
		if(A[i]==1)
		{
			count++;
			//if((count-1)%100==0)
				printf("%lld\n",i);
			for(j=i*i;j<=100000000;j+=i)
				A[j]=0;
		}
	}
	//printf("%lld\n%lld\n",count,T);
	return 0;
}