#include <stdio.h>
#include <iostream>
#include <cmath>
using namespace std;
int prime[2000]={0};
void shieve()
{
	prime[0]=1;
	prime[1]=1;
	int i,j;
	for(i=2;i*i<=100;i++)
	{
		if(prime[i]==0)
		{
			for(j=i*i;j<=100;j+=i){
				prime[j]=1;
			}
	}
}
}
int sum_even(int n)
{
	n=n/10;
	int sum=0;
	while(n)
	{
		sum+=n%10;
		n/=100;
	}
	return sum;
}
int sum_odd(int n)
{
	int sum=0;
	while(n)
	{
		sum+=n%10;
		n/=100;
	}
	return sum;
}
int main()
{
	int t;
	shieve();
	scanf("%d",&t);
	while(t--)
	{
		int i,temp,count=0;
		int a,b;
		scanf("%d%d",&a,&b);
		for(i=a;i<=b;i++)
		{
			temp=sum_even(i)-sum_odd(i);
			if(temp>=0)
				if(!prime[temp])
					count++;
		}
		cout<<count<<endl;
	}
	return 0;
}