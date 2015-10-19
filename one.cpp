#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair < int , int >
#define pb push_back
#define mp make_pair
#define mod 1000000009
int total = 0;
int calc(int a[] , int n){
	int res = 0;
	for(int i = 0 , j = n-1 ; i< n/2 ;j--, i++)
		res += abs(a[i] - a[j]);
	return res;
}
void ans(int a[] , int n , int pos){
	total = max(total , calc(a , n));
	for(int i = pos ; i< n-1 ; i++){
		if(a[i-1] %2 == 0 && a[i+1]%2==0){
			int save = a[i];
			a[i] = (a[i-1] + a[i+1])/2;
			ans(a , n , i+1);
			a[i] = save;
		}
	}
}
int main(){
	int t;
	cin >> t;
	while (t--){
		int n;
		cin >> n;
		int a[n+9];
		for (int i = 0; i < n; i++)
			cin >> a[i];
		total = 0;
		ans(a , n , 1);
		cout<<total<<endl;
	}
	
	return 0;
}