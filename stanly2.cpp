/*
===================================================
Name :- Nishant Raj
Email :- raj.nishant360@gmail.com
College :- Indian School of Mines
Branch :- Computer Science and Engineering
Time :- 25 September 2015 (Friday) 23:07
===================================================*/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
#define ll long long
#define pii pair < int , int >
#define pb push_back
#define mp make_pair
#define mod 1000000009
using namespace __gnu_pbds;
class data{
public:
	int num , pos , qpos;
	bool type;
	data(){num = 0 , pos = 0;}
	data(int a ,int b , bool typ , int q){
		num = a , pos = b , type = typ , qpos = q;
	}
};
bool cmp(const data &a , const data &b){
	return a.num == b.num ? a.type > b.type : a.num > b.num;
}
class compare{
public:
	bool operator()(const data &a , const data &b){
		return a.pos < b.pos;
	}
};
typedef tree<
data,
null_type,
compare,
rb_tree_tag,
tree_order_statistics_node_update>pbd_set;
int main(){
	pbd_set s;
	int n , q;
	scanf("%d%d",&n,&q);
	data arr[n+q+9];
	for(int i = 0 ; i < n ; i++){
		int a;
		scanf("%d", &a);
		arr[i] = data(a , i , 1 , 0);
	}
	for(int i = 0 ; i < q ; i++){
		int l , k;
		scanf("%d%d" , &l  ,&k);
		arr[n+i] = data(l , k , 0 , i);
	}
	sort(arr , arr + n+q , cmp);
	int ans[q+9];
	for(int i = 0 ; i < n+q ; i++){
		if(arr[i].type == 1){
			s.insert(arr[i]);
		} else{
			int order = arr[i].pos - 1;
			ans[arr[i].qpos] =(*s.find_by_order(order)).num;
		}
	}
	for(int i = 0 ; i < q ; i++)
		printf("%d\n", ans[i]);
	return 0;
}