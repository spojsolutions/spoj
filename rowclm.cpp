#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n,q;
	scanf("%d%d",&n,&q);
	long long ma=0,mi=0;
	long long row[n+9];
	long long  column[n+9];
	memset(row,0,sizeof(row));
	memset(column,0,sizeof(column));
	for(int i=0;i<q;i++)
	{
		char s[50];
		int num,val;
		scanf("%s%d%d",s,&num,&val);
		if(s[0] == 'R')
		{
			row[num] += val;
			if(row[num] > ma)
				ma = row[num];
		}
		else
		{
			column[num]+=val;
			if(column[num] > mi)
				mi = column[num];
		}		
	}
	printf("%lld\n",mi+ma);
	return 0;
}