/*
===================================================
Name :- Nishant Raj
Email :- raj.nishant360@gmail.com
College :- Indian School of Mines
Branch :- Computer Science and Engineering
Time :- 14 August 2015 (Friday) 01:23
===================================================*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair < int , int >
#define pb push_back
#define mp make_pair
#define mod 1000000009

int main(){
	int t;
	cin>>t;
	for(int test = 1 ; test<= t ; test++){
		int n;
		string dir;
		cin>>n>>dir;
		int arr[n+9][n+9];
		int ans[n+9][n+9];
		vector<int> v[n+9];
		memset(ans , 0 , sizeof ans);
		for(int i = 0 ; i < n ; i ++)
			for(int j = 0 ; j < n ; j++)
				cin>>arr[i][j];
		if(dir == "left"){
			for(int i = 0 ; i < n ; i++){
				for(int j = 0 ; j < n ; j++){
					if(arr[i][j]!=0)
						v[i].pb(arr[i][j]);
				}
				v[i].pb(1);
			}
			vector<int> res[n+9];
			for(int i = 0 ; i < n ; i++){
				for(int j = 1 ; j < v[i].size() ;j+=2){
					if(v[i][j] == v[i][j-1])
						res[i].pb(v[i][j] + v[i][j-1]);
					else{
						res[i].pb(v[i][j-1]);
						if(v[i][j]!=1)
							res[i].pb(v[i][j]);
					}
				}
			}
			cout<<"Case #"<<test<<":"<<endl;
			for(int i= 0 ; i < n ; i++){
				for(int j = 0 ; j < n ; j++){
					if(j < res[i].size())
						cout<<res[i][j]<<" ";
					else
						cout<<0<<" ";
				}
				cout<<endl;
			}
		}
		else if(dir == "right"){
			for(int i = 0 ; i < n ; i++){
				for(int j = n-1 ; j >=0 ; j--){
					if(arr[i][j]!=0)
						v[i].pb(arr[i][j]);
				}
				v[i].pb(1);
			}
			vector<int> res[n+9];
			for(int i = 0 ; i < n ; i++){
				for(int j = 1 ; j <v[i].size() ;j+=2){
					if(v[i][j] == v[i][j-1])
						res[i].pb(v[i][j] + v[i][j-1]);
					else{
						res[i].pb(v[i][j-1]);
						if(v[i][j]!=1)
							res[i].pb(v[i][j]);
					}
				}
				if(res[i].size() < n){
					for(int j = res[i].size() ; j< n ; j++)
						res[i].pb(0);
				}
			}
			cout<<"Case #"<<test<<":"<<endl;
			for(int i= 0 ; i < n ; i++){
				for(int j = n-1 ; j >=0 ; j--){
					cout<<res[i][j]<<" ";
				}
				cout<<endl;
			}
		}else if(dir == "down"){
			for(int i = 0 ; i < n ; i++){
				for(int j = n-1 ; j >=0 ; j--){
					if(arr[j][i]!=0)
						v[i].pb(arr[j][i]);
				}
				v[i].pb(1);
			}
			vector<int> res[n+9];
			for(int i = 0 ; i < n ; i++){
				for(int j = 1 ; j <v[i].size() ;j+=2){
					if(v[i][j] == v[i][j-1])
						res[i].pb(v[i][j] + v[i][j-1]);
					else{
						res[i].pb(v[i][j-1]);
						if(v[i][j]!=1)
							res[i].pb(v[i][j]);
					}
				}
				if(res[i].size() < n){
					for(int j = res[i].size() ; j< n ; j++)
						res[i].pb(0);
				}
			}
			cout<<"Case #"<<test<<":"<<endl;
			for(int i= n-1 ; i >=0 ; i--){
				for(int j = 0 ; j <n ; j++){
					cout<<res[j][i]<<" ";
				}
				cout<<endl;
			}
		} else if(dir == "up"){
			for(int i = 0 ; i < n ; i++){
				for(int j = 0 ; j <n ; j++){
					if(arr[j][i]!=0)
						v[i].pb(arr[j][i]);
				}
				v[i].pb(1);
			}
			vector<int> res[n+9];
			for(int i = 0 ; i < n ; i++){
				for(int j = 1 ; j <v[i].size() ;j+=2){
					if(v[i][j] == v[i][j-1])
						res[i].pb(v[i][j] + v[i][j-1]);
					else{
						res[i].pb(v[i][j-1]);
						if(v[i][j]!=1)
							res[i].pb(v[i][j]);
					}
				}
				if(res[i].size() < n){
					for(int j = res[i].size() ; j< n ; j++)
						res[i].pb(0);
				}
			}
			cout<<"Case #"<<test<<":"<<endl;
			for(int i= 0 ; i <n ; i++){
				for(int j = 0 ; j <n ; j++){
					cout<<res[j][i]<<" ";
				}
				cout<<endl;
			}
		}
	}
	return 0;
}