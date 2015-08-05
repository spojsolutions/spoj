#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
unsigned long A[1001];
int main()
{
	unsigned long num,sum,temp;
	int i,t,n,flage=0,j,k;
	scanf("%d",&t);
	while(t--)
	{
		flage=0;
		scanf("%d",&n);
		for(i=0;i<n;i++)
			scanf("%lu",&A[i]);
		scanf("%lu",&num);
		sort(A,A+n);
		for(i=0;i<n && flage==0;i++)
			for(j=0,k=n-1;j<k;)
			{
				sum=num-A[i];
				temp=A[j]+A[k];
				if(sum==temp && i!=j && i!=k){
					flage=1;
					break;
				}
				else if(i==j)
					j++;
				else if(i==k)
					k--;
				else if(sum<temp)
					k--;
				else if(sum>temp)
					j++;
			}
		if(flage)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}