#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <vector>
using namespace std;
int main()
{
	int t;
	vector<int> array;
	scanf("%d",&t);
	while(t--)
	{
		int n,flage=1,i,k;
		scanf("%d",&n);
		int *a=(int*)calloc(n+10,sizeof(int));
		int *r=(int*)calloc(n+10,sizeof(int));
		//int a[n+10],r[n+10];
		for(i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
		}
        for(int i=1;i<=n;i++){
			array.push_back(i);
		       }
		for(i=n;i>=1;i--)
		{
			k=i-a[i];
			r[i]=array[k-1];
			array.erase(array.begin()+(k-1));
		}
		for(i=1;i<=n;i++)
			printf("%d ",r[i]);
		printf("\n");
	}
	return 0;
}

