#include <bits/stdc++.h>
using namespace std;
#define MP make_pair
int check[1009][1009];
int min_x , min_y , max_x, max_y;
void lmt(int x , int y)
{
	min_x = min(min_x , x);
	min_y = min(min_y , y);
	max_x = max(max_x , x);
	max_y = max(max_y , y);
}
int main()
{
	int n;
	scanf("%d",&n);
	char s[n+9][n+9];
	char c = getchar_unlocked();
	for(int i = 0 ;  i < n ; i++)
		gets(s[i]);
	int count = 0;
	for(int i = 0 ; i < n ; i++)
	{
		for(int j = 0 ; j < n ; j++)
		{
			if(check[i][j] == 0 && s[i][j] == 'X')
			{
				queue<pair<int , int> > q;
				q.push(MP(i , j));
				min_x = 99999, min_y = 99999, max_x = -1, max_y = -1;
				while(!q.empty())
				{
					int x , y ;
					x = q.front().first;
					y = q.front().second;
					if(check[x][y]==0){
						lmt(x , y);
						if(x>0 && s[x-1][y] == 'X'){
							q.push(MP(x-1 , y));
						}
						if(x < n -1  && s[x+1][y] == 'X'){
							q.push(MP(x+1 , y));
						}
						if(y>0 && s[x][y-1] == 'X'){
							q.push(MP(x , y-1));
						}
						if(y < n -1  && s[x][y+1] == 'X'){
							q.push(MP(x , y+1));
						}
					}
					check[x][y] = 1;
					q.pop();
				}
				int flag = 0;
				for(int k = min_x ; k<=max_x ; k++)
				{
					for(int l = min_y ; l <= max_y ; l++)
					{
						if(s[k][l] == '0')
						{
							flag = 1 ;
							break;
						}
					}
				}
				if(flag == 0)
					count++;
			}
		}
	}
	printf("%d\n",count);
	return 0;
}

