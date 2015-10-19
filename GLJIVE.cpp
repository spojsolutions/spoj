/*
===================================================
Name :- Nishant Raj
Email :- raj.nishant360@gmail.com
College :- Indian School of Mines
Branch :- Computer Science and Engineering
Time :- 15 September 2015 (Tuesday) 00:51
===================================================*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair < int , int >
#define pb push_back
#define mp make_pair
#define mod 1000000009

int main(){
	
	int arr[10];
	for(int i = 0 ; i < 10 ; i++)
		cin>>arr[i];
	for(int i = 1 ; i< 10 ; i++)
		arr[i] += arr[i-1];
	vector<int> diff;
	for(int i = 0 ; i < 10 ; i++)
		diffp.pb(abs(arr[i] - 100));
	sort(diff.begin() , diff.end());
	if(binary_search(arr , arr+10 , 100-diff[0])){
		cout<<100 - diff[0]<<endl;
	} else
		cout<<100 + diff[0]<<endl;
	return 0;
}