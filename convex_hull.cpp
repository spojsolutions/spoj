#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <climits>
using namespace std;
class point
{
public:
	float x,y;
	int count;
	point()
	{
		x=0;
		y=0;
		count=0;
	}
	double slope(point p1)
	{
		point temp;
		temp.x=p1.x-x;
		temp.y=p1.y-y;
		return tan(x/y);
	}
	bool operator ==(point p1)
	{
		if(x==p1.x && y==p1.y)
			return true;
		else 
			return false;
	}
	bool operator !=(point p1)
	{
		if(x != p1.x || y != p1.y)
			return true;
		else 
			return false;
	}
};
int orientation(point p,point q,point r)
{
	int val=(q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
	if (val==0)
		return 0;
	return val>0?1:2;
}
void convexHull(point points[], int n)
{
    if (n < 3) return;
    int next[n];
    for (int i = 0; i < n; i++)
        next[i] = -1;
    int l = 0;
    for (int i = 1; i < n; i++)
        if (points[i].x < points[l].x)
            l = i;
    int p = l, q;
    do
    {
        q = (p+1)%n;
        for (int i = 0; i < n; i++)
          if (orientation(points[p], points[i], points[q]) == 2)
             q = i;
 
        next[p] = q;  
        p = q;
    } while (p != l);
    for (int i = 0; i < n; i++)
    {
        if (next[i] != -1)
           cout << "(" << points[i].x << ", " << points[i].y << ")\n";
    }
}
int main()
{
	point p[1000],convex_hull[1000],temp[1000];
	int n,k;
	cout<<"                 Enter the number of points\n";
	cin>>n;
	cout<<"                 Enter the co-ordinates of points\n";
	for(int i=0;i<n;i++)
	{
		cout<<"             Enter "<<i<<"th points\n";
		cin>>p[i].x>>p[i].y;
	}
	convexHull(p,n);
	return 0;
}