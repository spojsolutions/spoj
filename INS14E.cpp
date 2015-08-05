#include <bits/stdc++.h>
using namespace std;
#define MAX 510
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
template <class T>
T mi(T a, T b)
{
	return a<b?a:b;
}
template <class T>
inline T min_o(T a,T b,T c)
{
	return mi(a,mi(b,c));
}
template <class T>
T m(T a, T b)
{
	return a<b?b:a;
}
template <class T>
inline T max_o(T a,T b,T c)
{
	return m(a,m(b,c));
}
int main()
{
	int t;
	scan(t);
	while(t--)
	{
		double a[MAX][MAX];
		int n,m,temp,i,j;
		scan(m);scan(n);
		for(i=1;i<=m;i++)
			for(j=1;j<=n;j++){
				scan(temp);
				a[i][j] = temp;
			}
		for(i=m-1;i>=1;i--)
			a[i][n] += a[i+1][n];
		for(j=n-1;j>=1;j--)
			a[m][j] += a[m][j+1];
		for(i=m-1;i>=1;i--)
		{
			for(j=n-1;j>=1;j--)
				a[i][j] += 0.5*(min_o(a[i+1][j],a[i][j+1],a[i+1][j+1]) + max_o(a[i+1][j],a[i][j+1],a[i+1][j+1]));
		}
		printf("%0.6lf\n",a[1][1]);
	}
	return 0;
}