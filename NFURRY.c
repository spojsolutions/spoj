#include<stdio.h>
#include<math.h>
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,count=0,temp;
		scanf("%d",&n);
		temp=n;
		while(temp)
		{
			temp=temp-(((int)sqrt(temp))*((int)sqrt(temp)));
			count++;
		}
		printf("%d\n",count);
	}
	return 0;
}