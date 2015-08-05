#include <bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	map<string , int> mp;
	map<string , int>::iterator t;
	for(int i = 0 ; i < n ; i++)
	{
		string temp;
		cin>>temp;
		mp[temp] += 1;
	}
	for(t = mp.begin() ; t!= mp.end() ; t++){
		cout<<(*t).first<<" "<<(*t).second<<endl;
	}
	return 0;
}