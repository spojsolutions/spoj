#include<stdio.h>
#define MOD 1000000007
int N;
int T[2][2]={{1,1},{1,0}};
//int L[2][1]={{4},{4},{3},{4},{3},{3},{2},{3},{3},{33}};
void power(int R[2][2],int P)
{
	int i,j,k;
	if(P==1)
	{
		for(i=0;i<2;i++) for(j=0;j<2;j++) R[i][j]=T[i][j];
		return ;
	}
	int temp1[2][2]={0};
	int temp2[2][2]={0};
	long long int temp;
	power(temp1,P>>1);
	for(i=0;i<2;i++)
		for(j=0;j<2;j++)
		{
			temp=0;
			for(k=0;k<2;k++)
			{
				temp+=(long long)temp1[i][k]*temp1[k][j];
				if(temp>=MOD) temp%=MOD;
			}
			temp2[i][j]=temp;
		}
	if(P&1)
	{
		for(i=0;i<2;i++)
			for(j=0;j<2;j++)
			{
				temp=0;
				for(k=0;k<2;k++)
				{
					temp+=(long long)temp2[i][k]*T[k][j];
					if(temp>=MOD) temp%=MOD;
				}
				R[i][j]=temp;
			}
	}
	else
	{
		for(i=0;i<2;i++) for(j=0;j<2;j++) R[i][j]=temp2[i][j];
	}
}
int main()
{
	int t;
	int ANSWER[2][2];
	long long int ans;
	int i,j,k;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&N);
		if(N==1){printf("%d\n",1); continue;}
		if(N==2){printf("%d\n",1);continue;}
		power(ANSWER,N-2);
		ans=0;
		ans = ANSWER[0][0]+ANSWER[0][1];
		if(ans>=MOD) ans%=MOD;
		printf("%lld\n",ans);
	}
	//system("pause");
	return 0;
}