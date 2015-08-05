#include <bits/stdc++.h>
using namespace std;
void update(int index,int arr[],int tree[],int val)
{
	int temp = index;
	while(arr[temp] !=temp)
	{
		temp = arr[temp];
		tree[temp] +=val;
	}
}
int main()
{
	int n,q;
	scanf("%d%d",&n,&q);
	int arr[n+9],start,end;
	for(int i=1;i<=n;i++)
		arr[i] = i;
	for(int i=1;i<n;i++)
	{
		scanf("%d%d",&start,&end);
		arr[end] = start;
	}
	int value[n+9];
	int tree[n+9];
	memset(tree,0,sizeof(tree));
	for(int i=1;i<=n;i++){
		scanf("%d",&value[i]);
		if(value[i] == 0)
			update(i,arr,tree,1);
	}
	while(q--)
	{
		char c;
		scanf(" %c",&c);
		if(c=='Q')
		{
			scanf("%d",&start);
			printf("%d\n",tree[start]);
		}
		else
		{
			scanf("%d%d",&start,&end);
			if(value[start] == 0 && end!=0){
				value[start] = end;
				update(start,arr,tree,-1);
			}
			else if(value[start] !=0 && end == 0)
			{
				value[start] = 0;
				update(start,arr,tree,1);
			}
		}
	}
	return 0;
}