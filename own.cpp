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
		int n;
		scanint(n);
		int i,start,finish,j;
		int f[1000009]={0};
		int s[1000009]={0};
		for(i=0;i<n;i++)
		{
			scanint(start);
			scanint(finish);
			s[finish]=start;
			f[finish]=finish;
		}
		int k=0;
		for(i=0;i<=1000000;i++)
		{
			if(f[i]!=0)
			{
				s[k]=s[i];
				f[k]=f[i];
				k++;
			}
		}
		for(i=0;i<k;i++)
			cout<<f[i]<<" ";
		cout<<endl;
		int count=1;
		i=0;
		for(j=1;j<n;j++)
		{
			if(s[j]>=f[i])
			{
				count++;
				i=j;
			}
		}
		printf("%d\n",count);
	}
	return 0;
}