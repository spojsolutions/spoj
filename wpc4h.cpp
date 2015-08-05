#include <stdio.h>
#include <string>
#include <iostream>
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int i,count=1,max1[30]={0},max2[30]={0},high1,k;
		char temp;
		string s1,s2;
		cin>>s1>>s2;
		s1+='#';
		s2+='#';
		temp=s1[0];
		for(i=1;i<s1.size();i++)
		{
			k=temp-97;
			if(temp==s1[i])
			{
				count++;
			}
			else
			{
				if(max1[k]<count)
					max1[k]=count;
				count=1;
				temp=s1[i];
			}
		}
		count=1;
		temp=s2[0];
		for(i=1;i<s2.size();i++)
		{
			k=temp-97;
			if(temp==s2[i])
			{
				count++;
			}
			else if(max2[k]<count)
			{
				if(max2[k]<count)
					max2[k]=count;
				count=1;
				temp=s2[i];
			}
		}
		high1=-1;
		for(i=0;i<26;i++)
		{
			max1[i]+=max2[i];
			if(high1<max1[i])
				high1=max1[i];
		}
		printf("%d\n",high1);
	}
	return 0;
}