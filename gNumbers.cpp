/*
===================================================
Name :- Nishant Raj
Email :- raj.nishant360@gmail.com
College :- Indian School of Mines
Branch :- Computer Science and Engineering
Time :- 20 September 2015 (Sunday) 10:49
===================================================*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair < int , int >
#define pb push_back
#define mp make_pair
#define mod 1000000009
int prime[100009];
vector<int> pr;
void cal(){
	for(int i = 3 ; i*i <= 10000 ; i+=2){
		if(!prime[i]){
			for(int j = i*i ; j<= 10000 ; j+=i)
				prime[j] = 1;
		}
	}
	pr.pb(2);
	for(int i = 3 ; i<= 10000 ; i+=2){
		if(!prime[i])
			pr.pb(i);
	}
}
bool check_sum(ll n){
	int sum = 0;
	while(n){
		sum += n%10;
		n/=10;
	}
	if(sum <= 2)
		return true;
	if(!prime[sum] && sum%2 != 0){
		return true;
	}
	return false;
}
bool dfs(int num , int palyer){

	if(check_sum(num) && palyer==1)
		return true;
	cout<<num<<endl;
	int i = 0;
	while(pr[i] * pr[i] <= num){
		int temp;
		// cout<<pr[i]<<" ";
		while(temp%pr[i] == 0)
			temp/=pr[i];
		i++;
		if(temp!= num)
			if(dfs(temp , palyer^1)) return true;
	}
	return false;
}
int main(){
	int t;
	cin>>t;
	cal();
	for(int test = 1 ; test<= t ; test++){
		ll n;
		cin>>n;
		cout<<"Case #"<<test<<": ";
		int flag = 0;
		if(check_sum(n)){
			cout<<"dsaf";
			flag = 1;
		}
		if(flag == 0){
			cout<<"asdf";
			if(dfs(n , 0)) cout<<"Laurence"<<endl;
			else cout<<"Seymour"<<endl;
		} else cout<<"Seymour"<<endl;
	}
	
	return 0;
}