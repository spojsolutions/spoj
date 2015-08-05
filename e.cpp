#include <bits/stdc++.h>
using namespace std;
int main()
{
	string s="";
	while(s!="END"){
		getline(cin,s);
		if(s=="END")
			return 0;
		istringstream iss(s);
		string temp;
		int hash[30];
		memset(hash,0,sizeof(hash));
		while(iss>>temp){
			for(int i=0;i<temp.size();i++)
				hash[temp[i] - 65]++;
		}
		int flag=1;
		for(int i=0;i<26;i++)
			if(hash[i] > 1)
			{
				flag = 0;
				break;
			}
		if(flag)
			cout<<s<<endl;
	}
	return 0;
}