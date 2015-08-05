#include <stdio.h>
#include <cstdlib>
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,i,temp,flage=1;
		scanf("%d",&n);
		int *a;
		a=(int*)calloc(n+1,sizeof (int));
		for(i=0;i<n;i++)
		{
			scanf("%d",&temp);
			if(temp==n-1 && a[0]==0)
				a[0]=1;
			else if(a[temp]==0)
				a[temp]=1;
			else if(a[temp]==1 && a[n-1-temp]==0)
				a[n-1-temp]=1;
		}
		for(i=0;i<n;i++){
			if(a[i]==0){
				flage=0;
				break;
			}
		}
		if(flage==0)
			printf("NO\n");
		else
			printf("YES\n");
	}
	return 0;
}