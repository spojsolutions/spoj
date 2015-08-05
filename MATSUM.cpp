#include <bits/stdc++.h>
using namespace std;
#define LL long long 
LL tree[1050][1050];
void update(int x,int y,int val,int MAX)
{
	while(x<=MAX)
	{
		int ty = y;
		while(ty <= MAX)
		{
			tree[x][ty] += val;
			ty += (ty & -ty);
		}
		x += (x & -x);
	}
}
LL read(int x,int y)
{
	LL sum = 0;
	while( x )
	{
		int ty = y;
		while( ty )
		{
			sum += tree[x][ty];
			ty -= (ty & -ty);
		}
		x -= (x & -x);
	}
	return sum;
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		memset(tree,0,sizeof tree);
		while(1)
		{
			char s[10];
			scanf("%s",s);
			if(s[1] == 'E'){
				int x,y,val;
				scanf(" %d%d%d",&x,&y,&val);
				LL p_val = read(x+1,y+1) + read(x,y) - read(x+1,y) - read(x,y+1);
				update(x+1,y+1,val - p_val,n+9);
			}
			else if(s[1] == 'U')
			{
				LL sum = 0;
				int x1,y1,x,y;
				scanf(" %d%d%d%d",&x,&y,&x1,&y1);
				sum = read(x1+1,y1+1) + read(x,y) - read(x,y1+1) - read(x1+1 , y);
				printf("%lld\n",sum);
			}
			else{
				break;
			}
		}
		printf("\n");
	}
	return 0;
}