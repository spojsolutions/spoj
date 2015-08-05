//venk13
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <algorithm>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <cassert>

using namespace std;

#define sz(a) (int)(a.size())
#define len(a) (int)(a.length())
#define pb push_back
#define mp make_pair
#define fi first
#define se second

const int MAXN = 11;

long long a[MAXN], b[MAXN];
int n, m, p;

long long cnt(long long t, int w) {
	long long lo = 0, hi = 30000, res = -1;
	while(lo <= hi) {
		long long mid = (lo + hi) >> 1;
		long long n1 = mid, n2 = mid + 1;
		if(n1 & 1) n2 >>= 1; else n1 >>= 1;
		if(n1 * n2 * t > w) hi = mid - 1;
		else res = mid, lo = mid + 1;
	}
	return res;
}

bool works(int x) {
	long long cnt_a = 0;
	for(int i = 0; i < n; i++) {
		cnt_a += cnt(a[i], x);
	}
	long long cnt_b = 0;
	for(int i = 0; i < m; i++) {
		cnt_b += cnt(b[i], p - x);
	}
	return cnt_a <= cnt_b;
}

int main() {
	int t, cas = 1; cin >> t;
	while(t--) {
		cin >> p;
		cin >> n >> m;
		for(int i = 0; i < n; i++) {
			cin >> a[i];
		}
		for(int i = 0; i < m; i++) {
			cin >> b[i];
		}
		int lo = 0, hi = p, res = 0;
		while(lo <= hi) {
			int mid = (lo + hi) >> 1;
			if(works(mid)) res = mid, lo = mid + 1;
			else hi = mid - 1;
		}
		long long answer = 0;
		for(int i = 0; i < n; i++) {
			answer += cnt(a[i], res);
		}
		//if(cas > 1) cout << '\n';
		cout << answer << '\n';
		//++cas;
	}
	return 0;
}