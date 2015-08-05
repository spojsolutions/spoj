#include <stdio.h>
int main()
{
	int A[10][5]={0,0,0,0,0,
				  0,0,0,0,0,
				  6,2,4,8,4,
				  1,3,9,7,4,
				  6,4,0,0,2,
				  0,0,0,0,0,
				  0,0,0,0,0,
				  1,7,9,3,4,
				  6,8,4,2,4,
				  1,9,0,0,2,};
	int t;
	scanf("%d",&t);
	while(t--)
	{
		long long num,p;
		scanf("%lld%lld",&num,&p);
		int i,temp,k;
		if(p==0)
			printf("1\n");
		else{
			temp=num%10;
			if(temp==0)
				printf("0\n");
			else if(temp==1)
				printf("1\n");
			else if(temp==5)
				printf("5\n");
			else if(temp==6)
				printf("6\n");
			else{
				k=p%A[temp][4];
				printf("%d\n",A[temp][k]);
			}
		}
	}
return 0;
}