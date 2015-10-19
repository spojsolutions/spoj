/*
===================================================
Name :- Nishant Raj
Email :- raj.nishant360@gmail.com
College :- Indian School of Mines
Branch :- Computer Science and Engineering
Time :- 16 September 2015 (Wednesday) 21:06
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
	int arr[2*n+9][2*n+9];
	memset(arr , 0 , sizeof arr);
	for(int i = 2 ; i <= 2*n ; i++){
		for(int j = 1 ; j< i ; j++)
		{
			cin>>arr[i][j];
			arr[j][i] = arr[i][j];
		}
	}
	int par[2*n + 9];
	int vis[2*n + 9];
	memset(vis, 0, sizeof vis);
	for(int i = 1 ; i<= 2*n ; i++){
		//cout<<i<<endl;
		int prev = -1;
		if(vis[i]){
			continue;
		}
		vis[i] = true;
		for(int j = 1 ; j <= 2*n ; j++){
			// cout<<j<<" fd ";
			if(vis[j])
				continue;
			int temp = arr[i][j];
			int flag = 0;
			for(int k = 1 ; k<= 2*n ; k++){
				if(temp < arr[j][k]){
					flag = 1;
					break;
				}
			}
			if (!flag && prev < temp){
				vis[par[i]] = false;
				par[i] = j;
				par[j] = i;
				vis[j] = true;
				prev = temp;
			}
		}
	}
	for(int i = 1 ; i<= 2*n ; i++)
		cout<<par[i]<<" ";
	cout<<endl;
	return 0;
}