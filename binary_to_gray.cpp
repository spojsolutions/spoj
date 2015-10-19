/*
===================================================
Name :- Nishant Raj
Email :- raj.nishant360@gmail.com
College :- Indian School of Mines
Branch :- Computer Science and Engineering
Time :- 07 August 2015 (Friday) 00:37
===================================================*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair < int , int >
#define pb push_back
#define mp make_pair
#define mod 1000000009
string bin_to_gray(string bin , int n){
	string temp;
	if(n == 0){
		temp = bin[n];
		return temp;
	}
	int cur = bin[n] - 48;
	int last = temp[0] - 48;
	temp = (char)(last - cur + 48);
	temp = bin_to_gray(bin , n-1) + temp;
	cout<<n<<" "<<temp<<endl;
	return temp;
}
int main(){
	string s;
	cin>>s;
	cout<<bin_to_gray(s , s.size());
	return 0;
}