#include <stdio.h>
#include <cstring>
using namespace std;
int main()
{
	int t,i,a,b;
	char s[100005];
	scanf("%d",&t);
	while(t--)
	{
		scanf("%s",s);
		long long len=strlen(s);
		s[len]='#';
		long long temp=len,count=0,k;
		char temp1;
		scanf("%d%d",&a,&b);
		if(a<b){
			temp1='a';
			k=b-a;
			for(i=0;i<=len;i++)
			{
				if(temp1==s[i])
					count++;
				else
				{
					temp+=(count/a)*k;
					count=0;
				}
			}
			printf("%lld %lld\n",len,temp);
		}
		else if(a>b)
		{
			temp1='a';
			k=a-b;
			for(i=0;i<=len;i++)
			{
				if(temp1==s[i])
					count++;
				else
				{
					temp-=(count/a)*k;
					count=0;
				}
			}
			printf("%lld %lld\n",temp,len);
		}
		else
			printf("%lld %lld\n",len,len);
}
return 0;
}