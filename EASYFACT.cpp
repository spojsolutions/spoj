#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define gc getchar_unlocked
int prime[100000009];
vector<int>save;
void pre(){
	for(int i = 3 ; i*i <= 100000000 ; i+=2){
		if(!prime[i]){
			for(int j = i*i ; j<= 100000000 ; j+=i)
				prime[j] = 1;
		}
	}
	for(int j = 3 ; j<= 100000000 ; j+=2)
		if(!prime[j])
			save.pb(j);
}
inline void getInt(int &x)
{
    register int c = gc();
    x = 0;
    int neg = 0;
    for(;((c<48 || c>57) && c != '-');c = gc());
    if(c=='-') {neg=1;c=gc();}
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
    if(neg) x=-x;
}
int main(){
	pre();
	cout<<2<<" ";
	for(int i = 0 ; i < 100 ; i++)
		cout<<save[i]<<" ";
	cout<<endl;
	int t;
	getInt(t);
	while(t--){
		int n , m;
		getInt(n);getInt(m);
		ll ans=1 , cnt=0 , total_cnt=0;
		int size = save.size();
		for(int i = 0 ;i<size && (ll)save[i]*save[i] <= n ; i++){
			total_cnt = 0;
			for(int j = save[i] ; cnt = n/j ; j*=save[i])
				total_cnt += cnt;

			ans *= total_cnt + 1;
			if(ans >= m)
				ans %= m;
		}
		int start = n / sqrt(n);
		start = n / start;
		
		printf("%lld\n", (ans+m-1)%m);
	}
	return 0;
}