#include<stdio.h>
#include<math.h>
int main()
{
	int yr;
	long double pos,diff;
	while(scanf("%d%lld",&yr,&pos)!=NULL)
	{
		diff=pow(2,64)-pos;
		while(diff>=2)
		{
			int i=0;
			while(pow(2,i)-pos<0)
			{
				i++;
			}
			diff=pow(2,i)-pos;
			pos=diff;
		}
		if(diff==1&&yr%2!=0)
			printf("B");
		else
			printf("R");
	}
}