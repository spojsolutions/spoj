#include <bits/stdc++.h>
using namespace std;
string s;
int n;
void print(string temp , int k){
	if(k == 0){
		cout<<temp<<endl;
		return ;
	}
	for(int i = 0 ; i < n ; i++){
		string temp1 = temp + s[i];
		print(temp , k-1);
	}
}
int main(){
	int k;
	cin>>n>>k;
	cin>>s;
	print("" , k);
	return 0;
}