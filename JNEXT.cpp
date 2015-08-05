#include<stdio.h>
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
		int n,i,dig[10]={0},j,k;
		scanint(n);
		int A[n];
		for(i=0;i<n;i++){
			scanint(A[i]);
		}
		int max=-1;
		for(i=n-1;i>=0;i--)
		{
			if(A[i]<max){
				dig[A[i]]++;
				max=A[i];
				break;
			}
			else{
				dig[A[i]]++;
				max=A[i];
			}
		}
		if(i==-1)
			printf("-1");
		else
		{
			for(j=0;j<i;j++)
				printf("%d",A[j]);
			for(j=max+1;j<=9;j++)
			{
				if(dig[j]!=0)
				{
					printf("%d",j);
					dig[j]--;
					break;
				}
			}
			for(j=i+1;j<n;j++)
			{
				for(k=0;k<=9;k++)
				{
					if(dig[k]!=0)
					{
						printf("%d",k);
						dig[k]--;
						break;
					}
				}
			}
		}
		printf("\n");
	}
}