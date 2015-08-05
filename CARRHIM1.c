#include<stdio.h>
int main()
{
	int TIME=1;
	while(TIME--)
	{
		char T;
		int W=0,B=0,R,count=0,first,R1=0,R2=0,SUMW=0,SUMB=0;
		while(scanf("%c",&T)!='#')
		{
			scanf("%d%d%d",&W,&B,&R);
				if(count==0)
				{
					if(T==65||T==67)
						first=1;
					else
						first=2;
				}
				if(R!=0)
				{
					if(T==65||T==67)
						R1+=R;
					else
						R2+=R;
				}
				count++;
				printf("w=%d\n",W);
			
		}
	}
	return 0;
}