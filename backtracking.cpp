/*
===================================================
Name :- Nishant Raj
Email :- raj.nishant360@gmail.com
College :- Indian School of Mines
Branch :- Computer Science and Engineering
Time :- 05 August 2015 (Wednesday) 20:26
===================================================*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair < int , int >
#define pb push_back
#define mp make_pair
#define mod 1000000009
std::vector<int> v;
void subset_sum(vector<int> &a ,int sum , int pos){
	if(sum == 0){
		for(int i = 0 ; i < v.size() ; i++)
			cout<<v[i]<<" ";
		cout<<endl;
		v.pop_back();
		subset_sum(a , sum + a[pos] , pos+1);
	} else{
		for(int i = pos ; i<a.size() ; i++){
			v.push_back(a[i]);
			subset_sum(a , sum - a[i] , pos+1);
		}
	}
}
int main(){
	
	int n ,sum ;
	cin>>n>>sum;
	vector<int> a;
	for(int i = 0 ; i < n ; i++){
		int temp;
		cin>>temp;
		a.pb(temp);
	}
	subset_sum(a , sum , 0);
	return 0;
}