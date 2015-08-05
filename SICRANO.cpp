#include <stdio.h>
#include <iostream>
using namespace std;
struct point
{
	int x,y;
};
struct segment
{
	int x1,x2,y1,y2;
};
inline int check(segment s,point p)
{
	if((s.x1==p.x && s.y1==p.y) || (s.x2==p.x && s.y2 == p.y))
		return 1;
	int max_y,max_x,min_y,min_x;
	if(s.y2>s.y1){
		max_y=s.y2;
		min_y=s.y1;
	}
	else
	{
		max_y=s.y1;
		min_y=s.y2;
	}
	if(s.x1>s.x2)
	{
		max_x=s.x1;
		min_x=s.x2;
	}
	else
	{
		max_x=s.x2;
		min_x=s.x1;
	}
	if((s.x1==s.x2) && (s.x1==p.x && (p.y<=max_y && p.y >=min_y)))
		return 1;
	if((s.y1==s.y2) && (s.y1==p.y && (p.x<=max_x && p.x >=min_x)))
		return 1;
	if((s.x1==s.x2) || (s.y1==s.y2))
	{

	}
	if((s.y1-s.y2)*(p.x-s.x2)==(p.y-s.y2)*(s.x1-s.x2) &&  (p.y<=max_y && p.y >=min_y) && (p.x<=max_x && p.x >=min_x)){
		return 1;
	}
	return 0;
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int m,n,count=0,k;
		scanf("%d%d",&n,&m);
		point p[n];
		segment s;
		for(int i=0;i<n;i++)
			scanf("%d%d",&p[i].x,&p[i].y);
		for(int i=0;i<m;i++){
			scanf("%d%d%d%d",&s.x1,&s.y1,&s.x2,&s.y2);
			count=0;
			for(int j=0;j<n;j++)
			{
				k=check(s,p[j]);
				if(k)
					count++;
			}
			printf("%d\n",count);
		}
	}
}