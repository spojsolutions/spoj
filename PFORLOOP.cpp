#include <stdio.h>
#include <algorithm>
#include <cstdlib>
using namespace std;
long a[10000000];
int main()
{
	long n,i=0,j,d,start,end,count=0;
	while(scanf("%ld",&n)!=EOF)
	{
		a[i++]=n;
	}
	sort(a,a+i);
	for(j=1;j<=i;j++)
	{
		if(a[j]-a[j-1]==1){
			count++;
		}
		else
		{
			end=a[j-1];
			printf("for (int i = %ld; i <= %ld; i++) cout << i << “ “;\n",end-count,end);
			count=0;
		}
	}
	return 0;
}