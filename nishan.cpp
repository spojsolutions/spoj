#include <stdio.h>
#include <iostream>
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int i,a[15],mul=0,check[200]={0},j,count;
		for(i=2;i<=9;i++)
		{
			scanf("%d",&a[i]);
			mul+=a[i];
		}
		for(i=9;i>=2;i--)
		{
			count=0;
			for(j=mul;j>=1;j--)
			{
				if(a[i]==0)
					break;
				if(check[j]==0 && j%i!=0 )
				{
					check[j]=1;
					a[i]--;
				}
			}
			cout<<"i = "<<a[i]<<endl;
			count+=a[i];
		}
		printf("%d\n",mul+count);
	}
	return 0;
}