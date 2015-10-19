/*
===================================================
Name :- Nishant Raj
Email :- raj.nishant360@gmail.com
College :- Indian School of Mines
Branch :- Computer Science and Engineering
Time :- 25 September 2015 (Friday) 17:07
===================================================*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair < int , int >
#define pb push_back
#define mp make_pair
#define mod 1000000009

int main(){
	
	int n;
	cin>>n;
	int arr[n+9];
	for(int i = 0 ; i < n ; i++)
		cin>>arr[i];
	bool mask[n+9];
	memset(mask , 1 , sizeof mask);
	int ans = 0;
	vector<int> v;
	for(int j = 31 ; j>=0 ; j--){
		int a = (1<<j);
		int count = 0;
		for(int i = 0 ; i < n ; i++){
			if(!(a&arr[i]) && mask[i] == 1){
				mask[i] = 0;
				v.pb(i);
			}
			else{
				count++;
			}
		}
		if(count < 2){
			for(int i = 0 ; i < v.size() ; i++)
				mask[v[i]] = 1;
		}
		else
			ans += (1<<j);
		// cout<<ans<<endl;
	}
	cout<<ans<<endl;
	return 0;
}