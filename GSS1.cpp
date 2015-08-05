#include <bits/stdc++.h>
using namespace std;
int n=log(50000);
class node
{
public:
	int val;
	void merge(node &a,node &b)
	{
		val=min(a.val,b,val);
	}
}tree[1<<(n+1)];
void mergeup(int pos)
{
	int temp=pos>>1;
	while(temp>0)
	{
		tree[temp].merge(tree[temp*2],tree[temp*2+1]);
		temp>>=1;
	}
}
node query(int root,int left_most,int right_most,int u,int v)
{
	if(u<=left_most && v>=right_most)
		return tree[root];
	int mid = (left_most+right_most)>>1,
			left_child = root*2,
			right_child = left_child + 1;
	if(u<mid) 

}