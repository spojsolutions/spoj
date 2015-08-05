#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	string s;
	scanf("%d",&t);
	getline(cin , s);
	while(t--)
	{
		string  temp;
		getline(cin , s);
		istringstream iss(s);
		map<string , int> mp;
		while(iss>>temp)
		{
			mp[temp] = 1;
		}
		int n = mp.size();
		cout<<n<<endl;
	}
	return 0;
}