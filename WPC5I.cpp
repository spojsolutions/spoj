#include <bits/stdc++.h>
using namespace std;
#define gc getchar_unlocked
#define ULL unsigned long long
ULL GCD(ULL a,ULL b)
{
	return b==0?a:GCD(b,a%b);
}
inline void scan(ULL &x)
{
    register ULL c = gc();
    x = 0;
    ULL neg = 0;
    for(;((c<48 || c>57) && c != '-');c = gc());
    if(c=='-') {neg=1;c=gc();}
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
    if(neg) x=-x;
}
int main()
{
	ULL t;
	scan(t);
	while(t--)
	{
		unsigned long long a,b;
		scan(a);scan(b);
		unsigned long long temp,g,l;
		g=GCD(a,b);
		l = (a/g) * (b/g);
		printf("%llu\n",l);
	}
	return 0;
}