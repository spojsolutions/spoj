#include <bits/stdc++.h>
using namespace std;
#define gc getchar_unlocked
inline void scan(int &x)
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
	scan(t);
	while(t--)
	{
		int n;
		scan(n);
		int a[n],ma=INT_MIN,mi = INT_MAX,p_max,p_min;
		for(int i=0;i<n;i++){
			scan(a[i]);
			if(ma<a[i]){
				p_max=i;
				ma=a[i];
			}
			if(mi>a[i])
			{
				p_min = i;
				mi = a[i];
			}
		}
		long long d1,d2;
		d1= abs(ma*ma - mi*mi) + abs(p_min*p_min - p_max*p_max);
		d2 = abs(n*n - 1) + abs(a[n-1]*a[n-1] - a[0]*a[0]);
		printf("%lld\n",max(d1,d2));
	}
	return 0;
}