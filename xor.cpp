/*
===================================================
Name :- Nishant Raj
Email :- raj.nishant360@gmail.com
College :- Indian School of Mines
Branch :- Computer Science and Engineering
Time :- 25 September 2015 (Friday) 20:20
===================================================*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair < int , int >
#define pb push_back
#define mp make_pair
#define mod 1000000009

int main(){
	int N;
	cin>>N;
	int ans = N & (N % 2 ? 0 : ~0) | ( ((N & 2)>>1) ^ (N & 1) );
	cout<<ans<<endl;
	
	return 0;
}