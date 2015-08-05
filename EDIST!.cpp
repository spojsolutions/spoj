#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		char s[100009],t[100009],ns[100009],nt[100009];
		scanf("%s",s);
		scanf("%s",t);
		int sizes = strlen(s),sizet = strlen(t),a,b,k;
		scanf("%d%d%d",&a,&b,&k);
		if(a==0)
		{
			printf("0\n");
			continue;
		}
		if(b==0)
		{
			if(abs(sizet - sizes)*a > k)
				printf("-1\n");
			else
				printf("%d\n",abs(sizet - sizes)*a);
			continue;
		}
		if(abs(sizet - sizes)*a > k)
		{
			printf("-1\n");
			continue;
		}
		int l,p=0;
		for(l=0;l<min(sizet,sizes);l++)
		{
			if(s[l] != t[l])
			{
				ns[p] = s[l];
				nt[p] = t[l];
				p++;
			}
		}
		if(sizet < sizes)
		{
			sizet = p;
			while(l<sizes)
				ns[p++] = s[l++];
			sizes = p;
		}
		else
		{
			sizes = p;
			while(l<sizet)
				nt[p++] = t[l++];
			sizet = p;
		}
		if(abs(sizet - sizes)*a > k)
		{
			printf("-1\n");
			continue;
		}
		vector<int> v1(sizet+9),v2(sizet+9);
		for(int i=0;i<=sizet;i++)
			v1[i] = i*a;
		int flag = 0,mi = INT_MAX;
		for(int i=0;i<sizes;i++)
		{
			v2[0] = (i+1)*a;
			for(int j=0;j<sizet;j++)
			{
				int add;
				if(ns[i] == nt[j])
					add = 0;
				else 
					add = b;
				v2[j+1] = min(v2[j]+a,min(v1[j+1]+a,v1[j]+add));
			}
			for(int i=0;i<sizet;i++){
				mi = min(mi,v2[i]);
				v1[i] = v2[i];
			}
			if(mi > k){
				flag = 1;
				break;
			}
		}
		if(flag)
			printf("-1\n");
		else
			printf("%d\n",v2[sizet]);
	}
	return 0;
}