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
int num[1000009]={0};
void pre()
{
	for(int i=2;i<=1000;i++)
	{
		if(!num[i])
		for(int j=i*i;j<=1000000;j+=i)
			if(!num[j])
				num[j]=i;
	}
}
int main()
{
	int t;
	pre();
	scan(t);
	while(t--)
	{
		int n;
		scan(n);
		if(n&1){
			printf("0\n");
			continue;}
		n*=n;
		n>>=1;
		cout<<n<<endl;
		map<int ,int >mp;
		map<int ,int >::iterator t;
		if(num[n]!= 0)
			while(n%num[n] == 0)
			{
				mp[num[n]]+=1;
				if(num[n] == 0)
					break;
				n/=num[n];
				if(num[n]==0)
					break;
			}
		mp[n]+=1;
		int result =1;
		for(t=mp.begin();t!=mp.end();t++)
			result *= (t->second + 1);
		printf("%d\n",result);
	}
	return 0;
}


