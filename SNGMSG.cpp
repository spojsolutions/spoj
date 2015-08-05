#include <iostream>
#include <stdio.h>
#include <string>
#include <cstring>
using namespace std;
int main()
{
	int t;
	scanf("%d ",&t);
	while(t--)
	{
		char s[600],num[10],result[600],enc[50];
		gets(num);
		gets(s);
		int len_num,i=0,count,j=0,k=0,l;
		while(num[i]!='\0')
		{
			i++;
		}
		len_num=i;
		i=0;
		l=len_num-1;
		k=len_num;
		while(num[i]!='\0')
		{
			enc[j++]=num[i++];
			enc[k++]=num[l--];
		}
		enc[k]='\0';
		i=0;k=0;count=0;
		while(s[i]!='\0')
		{
			if(count>(2*len_num - 1))
				count=0;
			j=s[i]-(enc[count]-48);
			if(j<97)
				result[k++]=26+j;
			else
				result[k++]=j;
			i++;
			count++;
		}
		result[k]='\0';
		printf("%s\n",result);
	}
	return 0;
}