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
	int n,i=1;
	scanf("%d",&n);
	int *sum=(int *)calloc(n+9,sizeof(int));
	while(n--){
		scanint(temp);
		sum[i++]= sum[i-1] + temp ;
	}
	int m,check;
	scanint(m);
	while(m--)
	{
		scanint(check);
		if(check==0)
		{
			scanint(x);
			scanint(y);
			scanint(val);
			for(int )
		}
	}
}