#include<stdio.h>
int main()
{
	unsigned int t;
	scanf("%u",&t);
	while(t--)
	{
		int flage=1,i,N,data;
		scanf("%d",&N);
		for(i=0;i<N;i++)
		{
			scanf("%d",&data);
			if(data>i)
				flage=0;
		}
		if(flage==0)
			printf("NO\n");
		else
			printf("YES\n");
	}
	return 0;
}