#include <iostream>
#include <cmath>
#include <climits>
#include <cstdio>
using namespace std;
int main()
{
	int n,m,i,j,k,r,c,w;
	scanf("%d%d",&n,&m);
	int mat[n][n];
	for(i=0;i<n;i++)
		for(j=0;j<n;j++){
			mat[i][j]=INT_MAX;
		}
	for(i=0;i<m;i++)
	{
		scanf("%d%d%d",&r,&c,&w);
		mat[r][c]=w;
		mat[c][r]=w;
	}
	for(k=0;k<n;k++)
		for(i=0;i<n;i++)
			for(j=0;j<n;j++){
				mat[i][j] = min(mat[i][j],(mat[i][k] + mat[k][j]));
			}
	int q,a,b;
	scanf("%d",&q);
	for(i=0;i<q;i++)
	{
		scanf("%d%d",&a,&b);
		printf("%d\n",mat[a][b]);
	}
	return 0;
}