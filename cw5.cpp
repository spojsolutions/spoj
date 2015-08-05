#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	string s;
	cin>>s;
	string mu[15];
	int mi = 99999999,sz,ma = -1;
	for(int i=0;i<n;i++)
	{
		cin>>mu[i];
		sz = mu[i].size();
		mi = min(mi,sz);
		ma = max(ma,sz);
	}
	string result="",temp = "";
	for(int i = 0;i<n;i++)
	{
		for(int j = 0;j<s.size();j++)
		{
			temp = temp + s[i]
		}
	}
	cout<<result<<endl;
	return 0;
}