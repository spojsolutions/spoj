#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;
long long gcd(long long a,long long b)
{
	return b==0?a:gcd(b,a%b);
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		string s;
		cin>>s;
		long long sum=0;
		for(int i=0;i<s.size();i++)
		{
			sum+=(s[s.size() - 1 -i] - 48) * (1<<i);
		}
		cout<<sum<<endl;
	}	
}