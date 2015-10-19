/*
===================================================
Name :- Nishant Raj
Email :- raj.nishant360@gmail.com
College :- Indian School of Mines
Branch :- Computer Science and Engineering
Time :- 15 July 2015 (Wednesday) 21:27
===================================================*/
//question 312E codeforces
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair < int , int >
#define pb push_back
#define mp make_pair
#define mod 1000000007
ll pow_mod(ll a , ll b){
	ll ans = 1LL , p = a;
	while(b){
		if(b&1)
			ans = (ans*p)%mod;
		p = (p*p)%mod;
		b>>=1;
	}
	return ans;
}
int pri[1009];
void prime(){
	for(int i = 2 ; i*i <= 1000 ; i++){
		if(!pri[i]){
			for(int j = i*i ; j <= 1000 ; j+=i)
				pri[j] = i;
		}
	}
}
template<class T>
class segmentTree{
public:
	segmentTree(){
		height = 1;
		left_most = 1<<height;
		right_most = (left_most<<1) - 1; 
		tree = new T[right_most];
	}
	segmentTree(int s){ 
		size=s;
		height = ceil(log2(s));
		left_most = 1<<height;
		right_most = (left_most<<1) - 1;
		tree = new T[right_most+9];
	}
	void init(T * arr){
		build(arr);
	}
	void fill_ans(){
		initalize(1,left_most,right_most);
		for(int i = left_most ;i< left_most+size ; i++){
			for(int j=1;j<=26;j++)
				if(tree[i].arr[j]){
					cout<<char(j+96);
					break;
				}
		}
	}
	void print(){
		for(int i = 0 ; i<= right_most ; i++){
			cout<<i<<" - "<<tree[i].num<<" ";
			for(auto it:tree[i].v){
				cout<<it.first<<" -> "<<it.second<<" ";
			}
			cout<<endl;
		}
	}
	void Update(int pos , T val){
		point_update(1 , left_most , right_most , left_most+pos , val);
	}
	void Update(int l , int r , T val){
		range_update(1 , left_most , right_most , left_most+l , left_most+r , val);
	}
	T Query(int pos){
		return point_query(1 , left_most , right_most , left_most+pos);
	}
	T Query(int l ,int r){
		return range_query(1 , left_most , right_most , left_most+l , left_most+r);
	}
private:
	T *tree;
	int size , left_most , right_most , height;
	void build(T * arr){
		for(int i = 0 ; i < size ; i++)
			tree[left_most+i] = arr[i];
		initalize(1 , left_most , right_most); 
	}
	void initalize(int root , int left_most , int right_most){
		if(left_most == right_most) return;
		int mid = (left_most + right_most)>>1 , l_child = (root<<1)  , r_child = (root<<1)+1;
		tree[root].split(tree[l_child] , tree[r_child]);
		initalize(l_child , left_most , mid);
		initalize(r_child , mid+1 , right_most);
		tree[root].merge(tree[l_child] , tree[r_child]);
	}
	void point_update(int root , int left_most , int right_most , int pos , T val){
		if(left_most == right_most && root == pos) { tree[root].update(val); return ;}
		int mid = (left_most + right_most)>>1 , l_child = root<<1 , r_child = (root<<1)+1;
		tree[root].split(tree[l_child] , tree[r_child]);
		if(pos <= mid) point_update(l_child , left_most , mid , pos , val);
		else point_update(r_child , mid+1 , right_most , pos , val);
		tree[root].merge(tree[l_child] , tree[r_child]);
	}
	void range_update(int root , int left_most , int right_most , int l , int r , T val){
		if(l <= left_most && r >= right_most){ tree[root].update(val);return;}
		int mid = (left_most + right_most)>>1 , l_child = root<<1 , r_child = (root<<1)+1;
		tree[root].split(tree[l_child] , tree[r_child]);
		if(l <= mid) range_update(l_child , left_most , mid, l , r , val);
		if(r > mid) range_update(r_child , mid+1 , right_most , l , r , val);
		tree[root].merge(tree[l_child] , tree[r_child]);
	}
	T range_query(int root , int left_most ,int right_most ,int l , int r){
		if( l <= left_most && r >= right_most )
			return tree[root];
		int mid = (left_most + right_most)>>1 , l_child = root<<1 , r_child = (root<<1)+1;
		tree[root].split(tree[l_child] , tree[r_child]);
		T l_node  , r_node , temp;
		if(l <= mid) l_node = range_query(l_child , left_most , mid , l , r );
		if(r > mid) r_node = range_query(r_child , mid+1 , right_most , l , r );
		tree[root].merge(tree[l_child] , tree[r_child]);
		temp.merge(l_node , r_node);
		return temp;
	}
	T point_query(int root , int left_most , int right_most , int pos){
		if(left_most == right_most && root == pos) return tree[root];
		int mid = (left_most + right_most)>>1 , l_child = root<<1 , r_child = (root<<1)+1;
		T temp;
		tree[root].split(tree[l_child] , tree[r_child]);
		if(pos <= mid) temp = point_query(l_child , left_most , mid , pos);
		else temp = point_query(r_child , mid+1 , right_most , pos);
		tree[root].merge(tree[l_child] , tree[r_child]);
		return temp;
	}
};
class node{
public:
	ll num;
//	map<int , int> pf;
	vector<pair<int , int> > v;
	void merge(node &a , node &b){
		v.clear();
		auto it = a.v.begin() , it2 = b.v.begin();
		for(it = a.v.begin() , it2 = b.v.begin() ; it!= a.v.end() && it2!=b.v.end();){
//			auto x = b.pf.find(it->first);
//			if(x!=b.pf.end()){
//				pf[it->first] = max(it->second , x->second);
//			} else{
//				pf[it->first] =it->second;
//			}
			if((*it).first == (*it2).first){
				v.pb(mp((*it).first , max((*it).second , (*it2).second)));
				it++;
				it2++;
			} else if((*it).first < (*it2).first){
				v.pb(mp((*it).first , (*it).second));
				it++;
			} else{
				v.pb(mp((*it2).first , (*it2).second));
				it2++;
			}
		}
		while(it!= a.v.end()){
			//pf[it->first] = it->second;
			v.pb(mp((*it).first , (*it).second));
			it++;
		}
		while(it2!= b.v.end()){
			//pf[it2->first] = it2->second;
			v.pb(mp((*it2).first , (*it2).second));
			it2++;
		}
//		for(auto it = b.pf.begin() ; it!= b.pf.end() ; it++){
//			auto x = a.pf.find(it->first);
//			if(x!=a.pf.end()){
//				pf[it->first] = max(it->second , x->second);
//			} else{
//				pf[it->first] = it->second;
//			}
//		}
//		ll temp = 1;
//		for(auto it = pf.begin() ; it!=pf.end() ; it++){
//			for(int i = 0 ; i < it->second ; i++)
//				temp = (temp*(it->first))%mod;
//		}
//		num = temp;
	}
	void split(node &a , node &b){
	}
	void update(node &a){
		num = a.num;
		v = a.v;
	}
	node(){
		num = 0;
		v.clear();
	}
	node(int n){ 
		num=n;
		map<int , int> temp;
		while(pri[n]!=0){
			temp[pri[n]] +=1;
			n = n/pri[n];
		}
		if(pri[n] == 0)
			temp[n] +=1;
		for(auto it:temp)
			v.pb(mp(it.first , it.second));

		temp.clear();
	}
};
node arr[100009];
int main(){
	int n , temp ,q;
	prime();
	scanf("%d", &n);
	segmentTree<node> s(n);
	node arr[n];
	for(int i =0;i<n;i++){
		int temp;
		scanf("%d", &temp);
		arr[i]=node(temp);
	}
	s.init(arr);
	//s.print();
	scanf("%d", &q);
	while(q--){
		int type,l,r;
		scanf("%d %d %d", &type, &l, &r);
		if(type == 2){
			l--,r--;
			vector<pair<int , int> > pf = s.Query(l,r).v;
			ll temp = 1;
			for(auto it = pf.begin() ; it!=pf.end() ; it++){
				for(int i = 0 ; i < (*it).second ; i++)
					temp = (temp*((*it).first))%mod;
			}
			printf("%lld\n", temp);
		} else{
			l--;
			node temp = node(r);
			s.Update(l , temp);
			//s.print();
			//cout<<endl;
		}
	}
	return 0;
}