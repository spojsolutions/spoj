/*
===================================================
Name :- Nishant Raj
Email :- raj.nishant360@gmail.com
College :- Indian School of Mines
Branch :- Computer Science and Engineering
Time :- 06 August 2015 (Thursday) 21:00
===================================================*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair < int , int >
#define pb push_back
#define mp make_pair
#define mod 1000000009

int main(){
	
	int n , sum;
	cin>>n>>sum;
	int arr[n+9];
	for(int i = 0 ; i<n ; i++)
		cin>>arr[i];
	int k = (1<<n);
	for(int i = 1 ; i < k ; i++){
		int temp = i , pos = 0 , total = 0;
		vector<int> store;
		while(temp){
			if(temp&1){
				store.push_back(arr[pos]);
				total += arr[pos];
			}
			pos++;
			temp>>=1;
		}
		if(total == sum)
		{
			for(int j = 0 ; j <store.size() ; j++)
				cout<<store[j]<<" ";
			cout<<endl;
		}
	}	
	
	return 0;
}