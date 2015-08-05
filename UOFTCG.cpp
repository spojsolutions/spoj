#include <stdio.h>
#include <iostream>
#include <cstdlib>
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
		int n,m;
		scanint(n);
		scanint(m);
		int i,out_degree,in_degree;
		int total=2*n -1 ;
		int *out,*in;
		out=(int *)calloc(n+9,sizeof(int));
		in=(int *)calloc(n+9,sizeof(int));
		for(i=1;i<=m;i++)
		{
			scanint(out_degree);
			scanint(in_degree);
			out[out_degree]++;
			in[in_degree]++;
		}
		for(i=1;i<=n;i++)
		{
			if(out[i]!=0){
				total-=(out[i]-in[i]);
			}
		}
		printf("%d\n",total);
	}
	return 0;
}