#include <iostream>
#include <stdio.h>
#include <cstring>
#include <cmath>
using namespace std;
int main()
{
	int t;
	scanf("%d ",&t);
	while(t--)
	{
		char s1[200],s2[200];
		int count1[30]={0},count2[30]={0};
		gets(s1);
		gets(s2);
		char s[200];
		int len1=0,len2=0;
		for(int i=0;i<strlen(s1);i++)
		{
			if(s1[i]>=65 && s1[i]<=90){
				count1[s1[i]-65]++;
				len1++;}
			else if(s1[i]>=97  && s1[i]<=122){
				count1[s1[i]-97]++;
				len1++;}
		}
		for(int i=0;i<strlen(s2);i++)
		{
			if(s2[i]>=65 && s2[i]<=90){
				count2[s2[i]-65]++;
				len2++;}
			else if(s2[i]>=97  && s2[i]<=122){
				count2[s2[i]-97]++;
				len2++;}
		}
		int flage=1,count=0,sum=0,j,k,l,temp;
		if(len2==len1)
		{
			for(int i=0;i<26;i++)
				if(count2[i]!=count1[i]){
					flage = 0;
					break;
				}
			if(flage)
				printf("YES\n");
			else
				printf("NO LUCK\n");
		}
		else
		{
			int f=1;
			if(len2>len1)
			{
				f=1;
				for(int i=0;i<26;i++){
					if(count2[i]==0)
					{
					if(count1[i]!=0){
						f=0;
						break;}
					}
				}
				if(!f){
					printf("NO LUCK\n");
					continue;}
			}
			else
			{
				f=1;
				for(int i=0;i<26;i++){
					if(count1[i]==0)
					{
					if(count2[i]!=0){
						f=0;
						break;}
					}
				}
				if(!f){
					printf("NO LUCK\n");
					continue;}
			}
			for(int i=0;i<26;i++){
				count2[i]=(count2[i] - count1[i])<0?-1*(count2[i] - count1[i]):(count2[i] - count1[i]);
				sum+=count2[i];
				if(count2[i]%2!=0)
					count++;
			}
			if(sum%2==0 && count>0)
				flage=0;
			else if(sum%2!=0 && count>1)
				flage=0;

			if(flage==0)
				printf("NO LUCK\n");
			else
			{
				int flage1=0;
				for (int i=0; i<=7; i++)
					if (count2[i]%2==1)
					{
						flage1=1;
						flage=i;
					}	
				for (int i=0; i<26; i++)
				{
					k=count2[i]/2;
					count2[i]-=k;
					while(k--)
						printf("%c",i+97);
				}
				if (flage1==1)
					{
						printf("%c",flage+97);
						count2[flage]--;
					}
				for (int i=25; i>=0; i--)
				{
					while(count2[i]--)
						printf("%c",i+97);
				}

				printf("\n");
			}
		}
	}
	return 0;
}

