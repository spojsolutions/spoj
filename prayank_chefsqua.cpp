#include <bits/stdc++.h>
using namespace std;
#define limit 1000000
vector < int > v[2000010];
bool check(int x , int y)
{
	if(x < -1000000 || x > 1000000)
		return 0;
	if(y > 1000000 || y < -1000000)
		return 0;

	if(x < 0)
		x += 2000001;
	
	int size = v[x].size();
	

	if(!size)
		return 0;
	if(size == 1)
	{
		if(v[x][0] == y)
			return 1;
		else
			return 0;
	}
	int high = size , low = 0 , mid = 0 , prev = -1;
	while(prev != mid)
	{
		prev = mid;
		mid = (high + low)/2;
		if(v[x][mid] > y)
			high = mid;
		else if(v[x][mid] < y)
			low = mid;
		else
			return 1;
	}
	return 0;
}
int main()
{
	int n ,i ,j;
	scanf("%d",&n);
	int x[n] , y[n] , max = -100000000 ;
	for(i=0;i<n;i++)
	{
		scanf("%d%d",&x[i],&y[i]);
		if(x[i] >= 0)
			v[x[i]].push_back(y[i]);
		else
			v[x[i]+2000001].push_back(y[i]);
		
		if(max < x[i])
			max = x[i];
	}
	n = 0;
	int a[2000];
	for(i = 0 ; i <= max ; i++)
	{
		if(!v[i].size())
			continue;
		sort(v[i].begin(),v[i].end());
		int j , k = v[i].size() , cnt = 0;
		for(j = k-1 ; j >= 0 ; )
		{
			a[cnt] = v[i][j];
			while(v[i][j] == a[cnt] && j >= 0)
				j--;
			cnt++;
		}
		v[i].clear();
		for(j = cnt-1;j >= 0 ; j--)
		{
			v[i].push_back(a[j]);
			x[n] = i;
			y[n] = a[j];
			n++;
		}
	}
	if(n == 0)
		printf("4\n");
	else if(n==1)
		printf("3\n");
	else if(n==2)
		printf("2\n");
	else
	{
		int ans = 2 , flag = 0 ;
		float  m ,temp;
		long long int k2,k3,k4,k5,k;
		for(i=0;i<n;i++)
		{
			for(j=i+1;j<n;j++)
			{
				k2 = x[i];
				k3 = x[j];
				k4 = y[i];
				k5 = y[j];
				k = (k2-k3)*(k2-k3) + (k4-k5)*(k4-k5);

				if(!(k%2))
				{
					int xc,yc,xd,yd,x1,y1,x2,y2;
					xc = (x[i] + x[j])/2;
					yc = (y[i] + y[j])/2;
					xd = (x[i] - x[j])/2;
					yd = (y[i] - y[j])/2;

					x1 = xc - yd;
					y1 = yc + xd;
					x2 = xc + yd;
					y2 = yc - xd;
					
					if(check(x1,y1))
					{
						ans = 1;
						if(check(x2,y2))
						{
							ans = 0;
							flag = 1;
							break;
						}
						continue;
					}
					else if(check(x2,y2))
						ans = 1;
				}
			}
			if(flag)
				break;
		}
		printf("%d\n",ans);
	}
	return 0;
}