#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		string s,word,temp,prev="";
		cin>>s;
		istringstream iss(s);
		int count=0,max_count=-1;
		while(iss>>word)
		{
			if(prev.size() == word.size())
				count++;
			else
			{
				if(count>max_count)
					max_count = count;
				prev = word;
				count=0;
			}
		}
		cout<<max_count+1<<endl;
	}
	return 0;
}