#include <stdio.h>
#include <iostream>
using namespace std;
long long coins(long long n)
{
	if(n<12)
		return n;
	return max(n,coins(n/2)+coins(n/3)+coins(n/4));
}
int main()
{
	long long n;
	while(scanf("%lld",&n)!=EOF)
	{
		printf("%lld\n",coins(n));
	}
	return 0;
}