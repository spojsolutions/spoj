#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair < int , int >
#define pb push_back
#define mp make_pair
#define mod 1000000009
const int N = 888;
int arr[N][N];
int ans[N];
bool vis[N];

void dfs(int x, int par, int n){
	if (ans[x] != 0) return ;
	int mx = -1, idx = 0;
	for (int i = 1; i<=n; i++){
		if (ans[i] == 0 && arr[x][i] > mx){
			mx = arr[x][i];
			idx = i;
		}
	}
	if (idx == par && idx != 0){
		ans[idx] = x;
		ans[x] = idx;
	}
	else dfs(idx, x, n);
}
int main(){
	int n;
	cin >> n;
	n = n * 2;
	for (int i = 2; i<=n ;i++){
		for (int j = 1; j<i; j++){
			cin >> arr[i][j];
			arr[j][i] = arr[i][j];
		}
	}
	for (int i = 1; i<=n; i++) dfs(i, 0, n);
	// for (int i = 1; i<=n; i++){
	// 	int tmp = -1;
	// 	// if (vis[i]) continue;
	// 	// vis[i] = true;
	// 	if (ans[i]) continue;

	// 	for(int j = 1; j<=n; j++){
	// 		if (vis[j] || i == j) continue;
	// 		int temp = arr[i][j];
	// 		int flag = 0;

	// 		for (int k = 1; k<=n; k++){
	// 			// if (k == i) continue;
	// 			if (ans[k] == 0 && temp < arr[j][k]){
	// 				flag = 1;
	// 				break;
	// 			}
	// 		}
	// 		if (flag == 0 && tmp < arr[i][j]){
	// 			vis[ans[i]] = false;
	// 			vis[j] = true;
	// 			ans[i] = j;
	// 			ans[j] = i;
	// 			tmp = arr[i][j];
	// 		}
	// 	}
	// 	if (ans[i] != 0) vis[i] = 1; 
	// 	// for (int k = 1; k <= n; k++)
	// 	// 	cout << vis[k] << " ";
	// 	// cout << endl;
	// }
	for (int i = 1; i<=n; i++)
		cout << ans[i] << " ";
	cout << endl;
	return 0;
}