#include<stdio.h>
unsigned int P[10000002];
unsigned int RES[1000002];
int main()
{
	long N,i,j,l=0;
	for(i=0;i<=10000000;i++)
			P[i]=1;
	for(i=2;i<=10000000;i++)
	{
		if(P[i]==1)
		{
			RES[l++]=i;
			for(j=i*i;j<=10000000;j+=i)
				P[j]=0;
		}
	}
	while(scanf("%ld",&N)!=EOF)
	{
		long temp,k,m=0;
		char S[200];
		temp=N;
		k=0;
		S[m++]='1';
		while(temp!=0 && temp!=1)
		{
			if(temp % RES[k] ==0){
				S[m++]=32;
				S[m++]='x';
				S[m++]=32;
				S[m++]=RES[k]+48;
				temp=temp/RES[k];
			}
			else
				k++;
		}
		S[m]='\0';
		printf("%s\n",S);
	}
	return 0;
}
