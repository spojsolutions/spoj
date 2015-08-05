#include <iostream>
#include <stdio.h>
using namespace std;
int A[100000][11]={0};
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
void sqfree()
{
	int i,temp;
	int k,j;
	A[0][0]=1;
	for(i=2;i<=316;i++)
	{
		if(A[i][10]==0)
		{
			k=i*i;
			for(j=k;j<=100000;j+=k)
					A[j][10]=1;
		}
	}
	
	for(i=1;i<=100000;i++)
	{
		if(A[i][10]==0){
			temp=i;
			while(temp!=0)
			{
				A[i][temp%10]=1;
				temp/=10;
			}
			for(j=0;j<=9;j++)
			{
				A[i][j]+=A[i-1][j];
			}
		}
		else
			for(j=0;j<=9;j++)
				A[i][j]=A[i-1][j];
	}
}
int main()
{
	int t;
	sqfree();
	scanint(t);
	while(t--)
	{
		int low,high,digit;
		scanint(low);
		scanint(high);
		scanint(digit);
		printf("%d\n",A[high][digit]-A[low-1][digit]);
	}
	return 0;
}
