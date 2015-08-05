#include <bits/stdc++.h>
using namespace std;
#define INT 1000000009
#define pb push_back
int k;
struct node
{
	int val;
	void split(node &a , node &b)
	{
		a.val=min(a.val , val);
		b.val=min(b.val , val);
	}
	void merge(node a , node b)
	{
		
	}
}tree[262150];
void range_update(int root,int left_most ,int right_most , int l,int r,int val)
{
	if(l <= left_most && r >= right_most){
		tree[root].val = min(tree[root].val , val);
		return ;
	}
	int l_child = (root<<1) , r_child = l_child + 1 , mid = (left_most + right_most)>>1;
	tree[root].split(tree[l_child],tree[r_child]);
	if(l <= mid)
		range_update(l_child , left_most , mid , l , r , val);
	if(r > mid)
		range_update(r_child , mid+1 , right_most , l , r , val);
}
void propagate(int root ,int left_most , int right_most){
	if(left_most>=right_most)
		return;
	int l_child = (root<<1) , r_child = l_child + 1 , mid = (left_most + right_most)>>1;
	tree[root].split(tree[l_child] , tree[r_child]);
	propagate(l_child , left_most , mid);
	propagate(r_child , mid+1 , right_most);
}
void initalize(){
	for(int i = 0 ; i <= (1<<(k+1)) ; i++)
		tree[i].val = INT;
}
long long knapsack[100001][501];
int main()
{
	int t;
	scanf("%d" , &t);
	while(t--){
		int n , max_weight , m;
		scanf("%d%d%d" , &n , &max_weight , &m);
		k = ceil(log(n)/log(2));
		initalize();
		int arr[n+9];
		long long total = 0;
		for(int i  =0 ; i < n ; i++){
			scanf("%d" , &arr[i]);
			total += arr[i];
		}
		int pos = (1<<k);
		for(int i = 0;  i < m ; i++){
			int l , r , v;
			scanf("%d%d%d" , &l , &r , &v);
			if(v <= max_weight)
				range_update(1 , 1 , pos , l , r , v);
		}
		propagate(1 , 1 , pos);
		int weight[100009] , profit[100009];
		int count = 0;
		for(int i = 0 ; i < n ; i++)
			if(arr[i] < 0){
				weight[count] = tree[pos+i].val  , profit[count] = arr[i];
				count++;
			}
		int len =  count ;
		for(int i = 0 ; i <= len ; i++){
			for(int j = 0 ; j<= max_weight ; j++){
				if(i == 0 || j == 0)
					knapsack[i][j] = 0;
				else if(weight[i-1] <= j)
					knapsack[i][j] = min(profit[i-1] + knapsack[i-1][j - weight[i-1]] , knapsack[i-1][j]);
				else
					knapsack[i][j] = knapsack[i-1][j];
			}
		}
		printf("%lld\n" , total - knapsack[len][max_weight]);
	}
	return 0;
}
