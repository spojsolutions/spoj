#include <string>
#include <stdio.h>
#include <iostream>
using namespace std;
#define gc getchar_unlocked
inline void scanint(int &x)
{
    register int c = gc();
    x = 0;
    int neg = 0;
    for(;((c<48 || c>57) && c != '-');c = gc());
    if(c=='-') {neg=1;c=gc();}
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
    if(neg) x=-x;
}
int main()
{
	int t;
	scanint(t);
	while(t--)
	{
		int n,temp,l=0,j,i;
		//string s;
		char k,r[100];
		scanint(n);
		temp=n;
		if(n==0){
			printf("10\n");
		}
		else if(n<=9&& n>0){
			printf("%d\n",n);
		}
		else{
		for(i=9;i>=2;i--)
			{
				while(temp)
				{
					if(temp%i==0)
					{ 
						k=i+48;
						//s=k+s;
						r[l++]=k;
						temp/=i;
					}
					else{
						break;
					}
				}
			}
			if(temp==1){
				//cout<<s<<endl;
				for(j=l-1;j>=0;j--)
					printf("%c",r[j]);
				printf("\n");
			}
			else
				printf("-1\n");
		}
	}
	return 0;
}