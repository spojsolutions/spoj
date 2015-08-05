#include <bits/stdc++.h>
using namespace std;
#define MAX 100000
int bit[100001] , save[100001] , maxN;
void update(int x , int v){
	if(v >= 0){
		while(x <= MAX){
			save[x] = bit[x];
			bit[x] = min(bit[x] , v);
			x += (x & -x);
		}
	} else {
		while(x <= MAX){
			if(bit[x] == -1*v){
				bit[x] = save[x];
			}
			x += (x&-x);
		}
	}
}
int query(int x){
	int ans = 99999999;
	while(x > 0){
		ans = min(bit[x] , ans);
		x -= (x&-x);
	}
	return ans;
}
void rangeUpdate(int l , int r , int v){
	update(l , v);
	for(int i = 1 ; i <= maxN ; i++)
		cout<<query(i)<<" ";
	cout<<endl;
	update(r+1 , -v);
	for(int i = 1 ; i <= maxN ; i++)
		cout<<query(i)<<" ";
	cout<<endl;
}
int main(){
	int t;
	cin>>t;
	for(int i= 0 ; i<= 100000 ; i++)
		bit[i] = save[i] = 99999999;
	while(t--){
		int n;
		cin>>n>>maxN;
		for(int i =0 ; i < n ; i++){
			int l , r , v;
			cin>>l>>r>>v;
			rangeUpdate(l , r , v);
		}
		for(int i = 1 ; i <= maxN ; i++)
			cout<<query(i)<<" ";
		cout<<endl;
	}
	return 0;
}