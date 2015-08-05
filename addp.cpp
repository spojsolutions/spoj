#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
long long pow_mod(int a)
{
	long long res = 1,p=2;
	while(a)
	{
		if(a&1)
			res = (res*p)%MOD;
		p=(p*p)%MOD;
		a>>=1;
	}
	return res;
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		string a,b,result="";
		cin>>a>>b;
		int carry = 0;
		char c;
		for(int i=a.size()-1;i>=0;i--)
		{
			int sum = (a[i]+b[i] + carry - 96);
			if(sum==3){
				carry = 1;
				c = '1';
			}
			else if(sum == 2)
			{
				carry = 1;
				c = '0';
			}
			else if(sum == 1)
			{
				carry = 0;
				c = '1';
			}
			else if(sum == 0)
			{
				carry = 0;
				c= '0';
			}
			result = c + result; 
		}
		if(carry!=0){
			c = '1';
			result = c + result;
		}
		long long res=0;
		for(int i = result.size()-1,k=0;i>=0;i--,k++)
		{
			if(result[i] == '1')
				res =(res + pow_mod(k))%MOD;
		}
		cout<<result<<endl<<res<<endl;
	}
	return 0;
}