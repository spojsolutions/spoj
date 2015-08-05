#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		float f;
		char S[15];
		scanf("%s",S);
		int i=0,count=0,len,flage=0,t=1;
		len=strlen(S);
		for(i=len-1;i>=0;i--)
		{
			if(S[i]==46)
			{
				flage=1;
				break;
			}
			else
				count++;
		}
		if(flage==0)
			printf("1\n");
		else
		{
			f=atof(S);
			f-=(int)f;
			if(f==0)
				printf("1\n");
			else{
				for(i=0;i<count;i++)
				{
					t=t*10;
					f=f*10;
				}
				printf("%d\n",(int)(t/f));
			}
		}
	}

	return 0;
}