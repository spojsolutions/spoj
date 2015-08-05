#include<stdio.h>
#include<stdlib.h>
#include<iostream>
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
		int N,temp;
		scanint(N);
		temp=N;
		while(temp % 2==0) 
			temp=temp/2;
		if(temp % 3==0)
			temp=temp/3;
		if(temp % 5==0)
			temp=temp/5;
		if(temp % 17==0)
			temp=temp/17;
		if(temp % 257==0)
			temp=temp/257;
		if(temp % 65537==0)
			temp=temp/65537;
		if(temp==1)
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}