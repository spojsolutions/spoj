#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
int main(){
	int n;
	cin>>n;
	vector<pair<int , int > > v;
	int a , b;
	for(int i = 0 ; i < n ; i++){
		cin>>a>>b;
		v.pb(mp(a , b));
	}
	int count = 0;
	for(int i = 0 ; i < n ; i ++){
		for(int j = i+1 ; j<n ; j++){
			for(int k = j+1 ; k<n ; k++){
				float area = ((v[i].first*v[j].second + v[j].first*v[k].second + v[k].first*v[i].second) - (v[i].first*v[k].second + v[k].first*v[j].second + v[j].first*v[i].second))/2.0;
				if(area >0.0)
					count++;
			}
		}
	}
	cout<<count<<endl;
	return 0;
}