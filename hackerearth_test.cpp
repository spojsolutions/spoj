#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int vis[100010];
int prime[100010], c;

void sieve(int n)
{
	int m = sqrt(n+0.5);
	memset(vis, 0, sizeof(vis));
	vis[0] = vis[1] = 1;
	for(int i = 2; i <= m; i++)
		if(!vis[i])
			for(int j = i*i; j <= n; j += i)
				vis[j] = 1;
}

int get_primes(int n)
{
	sieve(n);
	int c = 0;
	for(int i = 2; i <= n; i++)
		if(!vis[i])
			prime[c++] = i;
	return c;
}
LL pow(LL a, LL b, LL n)
{
	LL ans = 1;
	while(b)
	{
		if(b&1)
		{
			ans *= a;
			ans %= n;
		}
		b >>= 1;
		a *= a;
		a %= n;
	}
	return ans;
}
LL work(LL x, LL y)
{
	LL ans = 0;
	while(x)
	{
		ans += x/y;
		x /= y;
	}
	return ans;
}
LL cm(LL n, LL m, LL p)
{
	LL ans = 1;
	for(int i = 0; prime[i] <= n && i < c; i++)
	{
		LL x = work(n, prime[i]);
		LL y = work(n-m, prime[i]);
		LL z = work(m, prime[i]);
		x -= y+z;
		ans *= pow(prime[i], x, p);
		ans %= p;
	}
	return ans;
}
LL cal(LL n, LL k, LL l, LL m)
{
	LL ans = 1;
	ans = ans * pow(k, l, n) % n;
	ans = ans * pow(k-1, m, n) % n;
	ans = ans * cm(l, m, n) % n;
	return ans;
}
int main()
{
	c = get_primes(100000);
	int T;
	int cas = 1;
	scanf("%d", &T);
	while(T--)
	{
		LL n, k, l, m;
		scanf("%lld %lld %lld %lld", &n, &k, &l, &m);
		if(m == 0)
		{
			printf("Case %d: %lld\n", cas++, pow(k, l, n)+1);
		}
		else if(k == 1)
			printf("Case %d: 1\n", cas++);
		else
			printf("Case %d: %lld\n", cas++, cal(2*n, k, l, m)/2+1);
		
	}
	return 0;
}