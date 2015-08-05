#include <stdio.h>
#include <cmath>
#include <string>
#include <iostream>
using namespace std;
long gcd(long a,long b)
{
	return b==0?a:gcd(b,a%b);
}
int main()
{
	int t,count,i,flage;
	scanf("%d",&t);
	while(t--)
	{
		string s;
		cin>>s;
		long number=1,frac;
		count=0;
		flage=0;
		for(i=s.size()-1;i>=0;i--)
		{
			if(s[i]=='.')
			{
				flage=1;
				break;
			}
			else
				count++;
		}
		for(i=0;i<s.size();i++)
		{
			if(s[i]!='.')
			{
				number=number*10 + (s[i]-48);
			}
		}
		frac=1;
		if(flage)
			frac=pow(10,count);
		printf("%ld\n",frac/gcd(number,frac));
	}
	return 0;
}
