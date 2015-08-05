#include<stdio.h>
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int N,i,j,count=0,flage=0,index;
		scanf("%d",&N);
		long r[N],R[N];
		for(i=0;i<N;i++)
		{
			scanf("%ld%ld",&r[i],&R[i]);
		}
		for(i=0;i<N;i++)
		{
			j=0,count=0;
			for(j=0;j<N;j++)
			{
				if(j!=i)
				{
					if(r[i]>R[j])
						count++;
					else{
						flage=0;
						break;
					}
				}
			}
			if(count==(N-1)){
				flage=1;
				index=i;
				break;
			}
		}
		if(flage==1)
			printf("%d\n",index+1);
		else
			printf("-1\n");
	}
	return 0;
}