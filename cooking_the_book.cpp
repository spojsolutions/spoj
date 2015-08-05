#include <bits/stdc++.h>
using namespace std;
#define LL long long
LL str_to_num(string str)
{
	LL num = 0;
	for(int i = 0 ; i < str.size() ; i++)
		num = num * 10 + str[i] - 48;
	return num;
}
int main()
{
	int t;
	cin>>t;
	for(int test = 1 ; test <= t ; test++){
		string s , temp;
		cin>>s;
		vector<string> v;
		v.push_back(s);
		for(int j = 0 ; j < s.size() ; j++){
			for(int i = j+1 ; i<s.size() ; i++){
				if(j==0){
					if(s[i] == 48){
						v.push_back(s);
					}
					else{
						swap(s[i] , s[j]);
						temp = s;
						v.push_back(temp);
						swap(s[i] , s[j]);
					}
				}
				else{
					swap(s[i] , s[j]);
					temp = s;
					v.push_back(temp);
					swap(s[i] , s[j]);
				}
			}
		}
		vector<LL> num;
		for(int i = 0 ; i < v.size() ; i++)
			num.push_back(str_to_num(v[i]));
		sort(num.begin() , num.end());
		cout<<"Case #"<<test<<": "<<num[0]<<" "<<num[num.size() - 1]<<endl;
	}
	return 0;
}