#include <bits/stdc++.h>
using namespace std;
#define MOD 10
int main()
{
	long long t;
	int temp,m;
	int res[10][5]={{0,0,0,0,1},
					{1,1,1,1,1},
					{6,2,4,8,4},
					{1,3,9,7,4},
					{6,4,0,0,2},
					{5,0,0,0,1},
					{6,0,0,0,1},
					{1,7,9,3,4},
					{6,8,4,2,4},
					{1,9,0,0,2},
				};
	scanf("%lld",&t);
	while(t--)
	{
		long long a,b;
		scanf("%lld%lld",&a,&b);
		if(b==0){
			printf("1\n");
			continue;}
		temp = a % MOD;
		m = b%res[temp][4];
		printf("%d\n",res[temp][m]);
	}
	return 0;
}