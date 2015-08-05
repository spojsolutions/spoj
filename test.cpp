#include <bits/stdc++.h>
using namespace std;
int a[100009][501];
class data{
	int l , r , v;
	data(){
		l = r = 100002;
		v = 99999999;
	}
	data(int left , int right , int val){
		l = left , r = right , v = value;
	}
};
bool cmp(const data &a , const data &b){
	return a.l==b.l ? a.r < a.r : a.l < b.l;
}
int whichCase(int l , int r , int p , int q){
	if((p>= l && q<=r) || p == r)
		return 0;
	if(p>l && p<r)
		return 1;
	if( p >= r)
}
int main(){
	int n , maxN;
	cin>>n>>maxN;
	data arr[n+9];
	for(int i = 0 ; i < n ; i++){
		int l , r , v;
		cin>>l>>r>>v;
		arr[i] = data(l , r , v);
	}
	sort(arr , arr+n , cmp);
	int result_array[100009];
	for(int i = arr[0].l , j =0; i<=maxN || j<n ;){
		int start = i , end = min(arr[j].r , arr[j+1].r);
		if(arr[j+1].l > arr[j].r){
			end+=1;
		}
		for(int k = start ; k<end ; k++)
			result_array[k] = arr[j].v;
		start = arr[j+1].l;
		end = min(arr[j].r , arr[j+1].r);
		for(int k = start ; k<= end ; k++)
			result_array[k] = min(arr[j].v , arr[j+1].val);
		
	}
}