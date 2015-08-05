/*
===================================================
Name :- Nishant Raj
Email :- raj.nishant360@gmail.com
College :- Indian School of Mines
Branch :- Computer Science and Engineering
Time :- 29 July 2015 (Wednesday) 01:20
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
	while(true){
		cin>>n;
		if(n == 0)
			return 0;
		int arr[n+9] , i = 0;
		for(int i = 0 ; i < n ; i++)
			cin>>arr[i];
		stack<int> s;
		long long ans = 0;
		for(i = 0;i < n;){
			if(s.empty() || arr[s.top()] <= arr[i])
				s.push(i++);
			else{
				int top = s.top();
				s.pop();
				long long mult = (s.size() ? i - s.top() -1: i );
				long long area = arr[top]*mult;
				ans = max(ans , area);
			}
		}
		while(!s.empty()){
			int top = s.top();
			s.pop();
			long long mult = (s.size() ? i - s.top() -1: i );
			long long area  = arr[top]*mult;
			ans = max(ans , area);
		}
		cout<<ans<<endl;
	}
	return 0;
}