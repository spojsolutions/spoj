#include <bits/stdc++.h>
using namespace std;
long long hash_value(string a)
{
	long long h=0;
	for(long long i=0; i<a.size(); i++)
	{
		h+=(i+1)*(long long)a[i];
	}
	h=h*19;
	return h%101;
}
vector<string> hash_table[101];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int q;
		scanf("%d",&q);
		START:
		while(q--)
		{
			string a;
			cin>>a;
			string x(a.begin()+4,a.end());
			if(a[0]=='A')
			{
				for(int i = 0 ; i < 101 ; i++)
				{
					if(!hash_table[i].empty()&&hash_table[i][0] == x)
						goto START;
				}
				int h=hash_value(x);
				for(int j=0; j<20; j++)
				{
					int idx=(h+j*j+23*j)%101;
					if(hash_table[idx].empty())
					{
						hash_table[idx].push_back(x);
						break;
					}
				}
			}
			else
			{
				int h=hash_value(x);
				for(int j=0; j<20; j++)
				{
					int idx=(h+j*j+23*j)%101;
					if(!hash_table[idx].empty()&&hash_table[idx][0]==x)
					{
						hash_table[idx].pop_back();
						break;
					}
				}
			}
		}
		int c=0;
		for(int i=0; i<101; i++)
			c+=hash_table[i].size();
		printf("%d\n",c);
		for(int i=0; i<101; i++)
		{
			if(!hash_table[i].empty())
				printf("%d:%s\n",i,hash_table[i][0].c_str());
		}
		for(int i=0; i<101; i++)
			hash_table[i].clear();
	}
	return 0;
}