#include<stdio.h>
int main()
{
	short unsigned int W,B,R,sumW,sumB,R1=0,R2=0,first,count=1;
	char TEAM[5];
	while(scanf("%s",t)!=EOF)
	{
		if(TEAM[0]!=35)
		{
			scanf("%d%d%d",&W,&B,&R);
			sumW+=W;
			sumB+=B;
			if(TEAM[0]==65||TEAM[0]==67)
			{
				if(count)
					first=1;
				if(R!=0)
					R1=5;
			}
			else
			{
				if(count)
					first=2;
				if(R!=0)
					R2=5;
			}
			count=0;
		}
		else
		{
			if((sumB==9||sumW==9)&&(R1!=0||R2!=0))
			{
				if(sumB==9)
				{
					if(first==1)
						printf("Team-2 win and the point is %u.\n",9- sumW+R2);
					else
						printf("Team-1 win and the point is %u.\n",9- sumW+R1);
				}
				else
				{
					if(first==1)
						printf("Team-1 win and the point is %u.\n",9- sumB+R1);
					else 
						printf("Team-2 win and the point is %u.\n",9- sumB+R2);
				}
			}
			else
				printf("Incomplete game.\n");
			count=1;
			sumB=0;
			sumW=0;
			R2=0;
			R1=0;
		}
	}
	return 0;
}