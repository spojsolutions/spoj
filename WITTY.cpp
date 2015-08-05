#include <stdio.h>
#include <iostream>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>
#include <climits>
int p2n2(int pos[],int neg[])
{
			int count=0;
			if(pos[0] + neg[0] == 0)
				count++;
			else if(pos[0] + neg[1] == 0)
				count++;
			if(count==1){
				return 2;
			}
			else
			{
				return 1;
			}
}
int p2n3(int pos[],int neg[])
{
	int count=0;
			if(pos[0] + neg[0]==0)
				count++;
			else if(pos[0] + neg[1] == 0)
				count++;
			else if(pos[0] + neg[2] ==0 )
				count++;
			if(count)
			{
				return 2;
			}
			else
			{
				if(pos[1] + neg[0]== 0)
					count++;
				else if(pos[1] + neg[2]==0)
					count++;
				else if(pos[1] + neg[1] == 0)
					count++;
				if(count)
				{
					return 2;
				}
				else
				{
					return 1;
				}
			}
}
int p3n2(int pos[],int neg[])
{
	int count=0;
			if(neg[0] + pos[0]==0)
				count++;
			else if(neg[0] + pos[1] == 0)
				count++;
			else if(neg[0] + pos[2] ==0 )
				count++;
			if(count)
			{
				return 2;
			}
			else
			{
				if(neg[1] + pos[0]== 0)
					count++;
				else if(neg[1] + pos[2]==0)
					count++;
				else if(neg[1] + pos[1] == 0)
					count++;
				if(count)
				{
					return 2;
				}
				else
				{
					return 1;
				}
			}
}
int p2n4(int pos[],int neg[])
{
	int count=0;
			if(pos[0] + neg[0]==0)
				count++;
			else if(pos[0] + neg[1] == 0)
				count++;
			else if(pos[0] + neg[2] ==0 )
				count++;
			else if(pos[0] + neg[3] ==0 )
				count++;
			if(count)
			{
				return 2;
			}
			else
			{
				if(pos[1] + neg[0]== 0)
					count++;
				else if(pos[1] + neg[2]==0)
					count++;
				else if(pos[1] + neg[1] == 0)
					count++;
				else if(pos[1] + neg[3] ==0 )
					count++;
				if(count)
				{
					return 2;
				}
				else
				{
					return 1;
				}
			}
}
int p4n2(int pos[],int neg[])
{
	int count=0;
			if(neg[0] + pos[0]==0)
				count++;
			else if(neg[0] + pos[1] == 0)
				count++;
			else if(neg[0] + pos[2] ==0 )
				count++;
			else if(neg[0] + pos[3] ==0 )
				count++;
			if(count)
			{
				return 2;
			}
			else
			{
				if(neg[1] + pos[0]== 0)
					count++;
				else if(neg[1] + pos[2]==0)
					count++;
				else if(neg[1] + pos[1] == 0)
					count++;
				else if(neg[1] + pos[3] ==0 )
					count++;
				if(count)
				{
					return 2;
				}
				else
				{
					return 1;				}
			}
}
using namespace std;
int main()
{
	int t;
	scanf("%d ",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		int out[10]={0};
		int in[10]={0},spend,pos_o,pos_i;
		string s1,s2;
		while(n--)
		{
			cin>>s1>>s2;
			cin>>spend;
			if(s1=="A")
				pos_o=0;
			else if(s1=="B")
				pos_o=1;
			else if(s1=="AA")
				pos_o=2;
			else if(s1=="BB")
				pos_o=3;
			else if(s1=="AB")
				pos_o=4;
			else 
				pos_o=5;
			out[pos_o]+=spend;

			if(s2=="A")
				pos_i=0;
			else if(s2=="B")
				pos_i=1;
			else if(s2=="AA")
				pos_i=2;
			else if(s2=="BB")
				pos_i=3;
			else if(s2=="AB")
				pos_i=4;
			else 
				pos_i=5;
			out[pos_i]-=spend;
		}
		int i,j,k,l,m,flag=0,neg[6],pos[6];
		int count_z=0,count_n=0,count_p=0,trans;
		for(i=0;i<6;i++)
		{
			if(out[i]==0)
				count_z++;
			if(out[i]<0){
				neg[count_n]=out[i];
				count_n++;
			}
			if(out[i]>0){
				pos[count_p]=out[i];
				count_p++;
			}
		}
		if(count_z==6){
			printf("0\n");
			continue;
		}
		if(count_p==1 || count_n== 1){
			printf("%d\n",5 - count_z);
			continue;
		}
		if(count_p==2 && count_n==2){
			printf("%d\n",4-p2n2(pos,neg));
			continue;
		}
		if(count_p==2 && count_n==3)
		{
			printf("%d\n",5-p2n3(pos,neg));
			continue;
		}
		if(count_p==3 && count_n==2)
		{
			printf("%d\n",5-p3n2(pos,neg));
			continue;
		}
		if(count_p==2 && count_n==4 )
		{
			printf("%d\n",6-p2n4(pos,neg));
			continue;
		}
		if(count_p==4 && count_n==2 )
		{
			printf("%d\n",6-p4n2(pos,neg));
			continue;
		}
		if(count_p==3 && count_n==3)
		{
			if(pos[0] + neg[0]==0)
			{
				pos[0]=pos[1];pos[1]=pos[2];
				neg[0]=neg[1];neg[1]=neg[2];
				printf("%d\n",5-p2n2(pos,neg));
				continue;
			}
			if(pos[0] + neg[1]==0)
			{
				pos[0]=pos[1];pos[1]=pos[2];
				neg[1]=neg[2];
				printf("%d\n",5-p2n2(pos,neg));
				continue;
			}
			if(pos[0] + neg[2]==0)
			{
				pos[0]=pos[1];pos[1]=pos[2];
				printf("%d\n",5-p2n2(pos,neg));
				continue;
			}
			if(pos[1] + neg [0]==0)
			{
				pos[1]=pos[2];
				neg[0]=neg[1];neg[1]=neg[2];
				printf("%d\n",5-p2n2(pos,neg));
				continue;
			}
			if(pos[1] + neg [1]==0)
			{
				pos[1]=pos[2];
				neg[1]=neg[2];
				printf("%d\n",5-p2n2(pos,neg));
				continue;
			}
			if(pos[1] + neg[2]==0)
			{
				pos[1]=pos[2];
				printf("%d\n",5-p2n2(pos,neg));
				continue;
			}
			if(pos[2] + neg[0]==0)
			{
				neg[0]=neg[1];neg[1]=neg[2];
				printf("%d\n",5-p2n2(pos,neg));
				continue;
			}
			if(pos[2] + neg[1]==0)
			{
				neg[1]=neg[2];
				printf("%d\n",5-p2n2(pos,neg));
				continue;
			}
			if(pos[2] + neg[2]==0)
			{
				printf("%d\n",5-p2n2(pos,neg));
				continue;
			}
			if(pos[0]+pos[1]+neg[0]==0)
			{
				printf("4\n");
				continue;
			}
			if(pos[0]+pos[2]+neg[0]==0)
			{
				printf("4\n");
				continue;
			}
			if(pos[1]+pos[2]+neg[0]==0)
			{
				printf("4\n");
				continue;
			}
			if(pos[0]+pos[1]+neg[1]==0)
			{
				printf("4\n");
				continue;
			}
			if(pos[0]+pos[2]+neg[1]==0)
			{
				printf("4\n");
				continue;
			}
			if(pos[1]+pos[2]+neg[1]==0)
			{
				printf("4\n");
				continue;
			}
			if(pos[0]+pos[1]+neg[2]==0)
			{
				printf("4\n");
				continue;
			}
			if(pos[0]+pos[2]+neg[2]==0)
			{
				printf("4\n");
				continue;
			}
			if(pos[1]+pos[2]+neg[2]==0)
			{
				printf("4\n");
				continue;
			}
			if(neg[0]+neg[1]+pos[0]==0)
			{
				printf("4\n");
				continue;
			}
			if(neg[0]+neg[2]+pos[0]==0)
			{
				printf("4\n");
				continue;
			}
			if(neg[1]+neg[2]+pos[0]==0)
			{
				printf("4\n");
				continue;
			}
			if(neg[0]+neg[1]+pos[1]==0)
			{
				printf("4\n");
				continue;
			}
			if(neg[0]+neg[2]+pos[1]==0)
			{
				printf("4\n");
				continue;
			}
			if(neg[1]+neg[2]+pos[1]==0)
			{
				printf("4\n");
				continue;
			}
			if(neg[0]+neg[1]+pos[2]==0)
			{
				printf("4\n");
				continue;
			}
			if(neg[0]+neg[2]+pos[2]==0)
			{
				printf("4\n");
				continue;
			}
			if(neg[1]+neg[2]+pos[2]==0)
			{
				printf("4\n");
				continue;
			}
			printf("5\n");
			continue;
		}
	}
	return 0;
}