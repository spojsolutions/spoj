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
		if(n&1){
			printf("0\n");
			continue;}
		int temp = sqrt(n);
		int flag=0,count=0;
		if(temp*temp == n)
			flag=1;
		for(int i=1;i<=n;i++)
			if(n%i == 0)
				count+=2;
		if(flag)
			count-=1;
		printf("%d\n",count);
	}
	return 0;
}


