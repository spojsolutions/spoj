#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,k;
		char s[1009];
		scanf("%d%d",&n,&k);
		vector<int>one,zero;
		scanf("%s",s);
		for(int i=0;i<n;i++)
		{
			if(s[i] == 48)
				zero.push_back(i);
			else
				one.push_back(i);
		}
		int count=1,j;
		for(int i=0,j=0;count <= n-k;count++)
		{
			if(count&1){
				if(i<one.size())
					s[one[i++]] = 50;
				else
					s[zero[j++]]=50;
			}
			else{
				if(j<zero.size())
					s[zero[j++]] = 50;
				else
					s[one[i++]]=50;
			}
		}
		for(int i=0;i<n;i++)
			if(s[i]!=50)
				printf("%c",s[i]);
		printf("\n");
	}
	return 0;
}