/*
===================================================
Name :- Nishant Raj
Email :- raj.nishant360@gmail.com
College :- Indian School of Mines
Branch :- Computer Science and Engineering
Time :- 12 August 2015 (Wednesday) 02:50
===================================================*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define pii pair < int , int >
#define pb push_back
#define mp make_pair
#define mod 1000000009
#define PI 3.14159
ld area(vector<ll> &v){
	ld total = 0.0;
	total+= sqrt(4*v[0]*v[0]*v[1]*v[1] - (v[0]*v[0] + v[1]*v[1] - v[3]*v[3]));
	total+= sqrt(4*v[0]*v[0]*v[2]*v[2] - (v[0]*v[0] + v[2]*v[2] - v[4]*v[4]));
	total+= sqrt(4*v[1]*v[1]*v[2]*v[2] - (v[1]*v[1] + v[2]*v[2] - v[5]*v[5]));
	total+= sqrt(4*v[3]*v[3]*v[4]*v[4] - (v[3]*v[3] + v[4]*v[4] - v[5]*v[5])); 
	return total/4;
}
ld b_search(ld a , ll ma){
	ld low = 0.0 , mid , high = ma;
	ld ans ;
	while(high-low > 1e-4){
		mid = (low+high)/2.0;
		ld v = pi*
	}
}
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		vector<ll> v(6);
		lld ma = INT_MIN;
		for(int i = 0 ; i < 6 ; i++){
			scanf("%lld",&v[i]);
			ma = max(ma , v[i]);
		}
		ld a = area(v);

	}
	return 0;
}