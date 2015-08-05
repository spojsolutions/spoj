#include <iostream>
#include <stdio.h>
#include <string>
#include <cstring>
#define LL long long
using namespace std;
char *strrev(char *str)
{
      char *p1, *p2;

      if (! str || ! *str)
            return str;
      for (p1 = str, p2 = str + strlen(str) - 1; p2 > p1; ++p1, --p2)
      {
            *p1 ^= *p2;
            *p2 ^= *p1;
            *p1 ^= *p2;
      }
      return str;
}
int main()
{
	int t;
	LL fact[16];
	fact[0]=1;
	for(int i=1;i<=15;i++)
	{
		fact[i]=fact[i-1]*i;
	}
	scanf("%d ",&t);
	while(t--)
	{
		string s;
		cin>>s;
		if(s=="Integer")
		{
			int num;
			scanf("%d",&num);
			printf("%lld\n",fact[num]);
		}
		else if(s=="Long")
		{
			LL l_num;
			int sum=0;
			scanf("%lld",&l_num);
			while(l_num)
			{
				sum+=l_num%10;
				l_num/=10;
			}
			printf("%d\n",sum);
		}
		else if(s=="String")
		{
			char s1[200];
			scanf("%s",s1);
			printf("%s\n",strrev(s1));
		}
		else
		{
			double f;
			scanf("%lf",&f);
			printf("%d\n",(int)f);
		}
	}
	return 0;
}