#include <bits/stdc++.h>
using namespace std;
#define LL long long
LL fibo(int n)
{
	if(n==0 || n==1)
		return 1;
	return fibo(n-2) + fibo(n-1);
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		if(n<0)
		{
			cout<<"you fool\n";
			continue;
		}
		cout<<fibo(n)<<endl;
	}
	return 0;
}