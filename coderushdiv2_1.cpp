#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define LL long long
LL odd[5000009];
LL even[5000009];
void pre()
{
	LL a=0 , b  = 1 ,res = 0 , j = 2 , k = 2;
	even[1] = 1;
	for(int i = 3 ; i<=10000000 ; i++)
	{
		res = (a + b)%MOD;
		a = b;
		b = res ;
		if(i&1){
			odd[k] = (res + odd[k-1])%MOD;
			k++;
		}
		else{
			even[j] = (res + even[j-1])%MOD;
			j++;
		}
	}
}
int main()
{
	int t;
	pre();
	cin>>t;
	while(t--)
	{
		int n , m ;
		cin>>n>>m;
		cout<<(even[n] - odd[m] + MOD)%MOD<<endl;
	}
	return 0;
}