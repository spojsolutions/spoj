#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair < int , int >
#define pb push_back
#define mp make_pair
#define mod 1000000009
int main(){
	
	int t;
	cin>>t;
	for(int test =1 ; test <= t ; test++){
		int a , b , c;
		cin>>a>>b>>c;
		vector<int> aa , bb , cc;
		for(int i = 0 ; i < a ; i++){
			int temp;
			cin>>temp;
			aa.pb(temp);
		}
		for(int i = 0 ; i < b ; i++){
			int temp;
			cin>>temp;
			bb.pb(temp);
		}
		for(int i = 0 ; i < c ; i++){
			int temp;
			cin>>temp;
			cc.pb(temp);
		}
		int q;
		cin>>q;
		cout<<"Case #"<<test<<": "<<endl;
		map<pii , vector<int>> hold;
		vector<pair< int , pii > > v ;
		vector<pii> v1;
		for(int i = 0 ; i < a ; i++){
			for(int j = 0 ; j < b ; j++){
				ll temp = __gcd(aa[i] , bb[j]);
				v.push_back(mp(bb[j] , mp(aa[i]/temp , bb[j]/temp)));
			}
		}
		for(int i = 0 ; i < b ; i++){
			for(int j = 0 ; j < c ; j++){
				ll temp = __gcd(bb[i] , cc[j]);
				hold[mp(bb[i]/temp , cc[j]/temp)].push_back(bb[i]);
			}
		}
		for(int qp = 0 ; qp < q ; qp++){
			ll n , d;
			cin>>n>>d;
			ll gcd = __gcd(n , d);
			n/=gcd;
			d/=gcd;
			int flag = 0;
			for(int i = 0 ; i < v.size() ; i++){
				ll xx = v[i].second.second * n;
				ll yy = v[i].second.first * d;
				ll gcd = __gcd(xx , yy);
				xx/=gcd;
				yy/=gcd;
				pii temp  = mp(xx, yy);
				auto it = hold.find(temp);
				if(it != hold.end()){
					for(auto x:it->second)
						if(x != v[i].first){
							flag = 1;
							break;
						}
				}
				if(flag)
					break;
			}
			if(flag){
				cout<<"Yes"<<endl;
			} else
				cout<<"No"<<endl;
		}
	}
	
	return 0;
}