/*
===================================================
Name :- Nishant Raj
Email :- raj.nishant360@gmail.com
College :- Indian School of Mines
Branch :- Computer Science and Engineering
Time :- 18 October 2015 (Sunday) 17:10
===================================================*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair < int , int >
#define pb push_back
#define mp make_pair
#define mod 1000000009
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
    int count , number;
    void merge(node &l , node &r){
        if(l.number == r.number){
            count = l.count + r.count;
            number = l.number;
        } else {
            if( l.count > r.count ){
                count = l.count - r.count;
                number = l.number;
            } else{
                count = r.count - l.count;
                number = r.number;
            }
        }
    }
    void split(node &a , node &b){
    }
    void update(node &a){
    }
    node(){
        count = 0  , number = 0;
    }
    node(int num){
        count = 1;
        number = num;
    }
};
node arr[300009];
vector<int> Index[100009];
int main(){
    int n , c;
    scanf("%d%d",&n , &c);
    int temp;
    for(int i = 0; i < n ; i++){
        scanf("%d",&temp);
        Index[temp].pb(i);
        arr[i] = node(temp);
    }
    segmentTree<node> s(n);
    s.init(arr);
    int q , l , r;
    scanf("%d",&q);
    while(q--){
        scanf("%d%d",&l,&r);
        l-- , r--;
        int num = s.Query(l , r).number;
        int count = upper_bound(Index[num].begin() , Index[num].end() , r) - lower_bound(Index[num].begin() , Index[num].end() , l);
        int req = r - l +1;
        if(count*2 > req){
            printf("yes %d\n", num);
        } else
            printf("no\n");
    }
    return 0;
} 