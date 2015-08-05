#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	for(int test = 1 ; test<= t; test++){
		int hh , mm , tt , I;
		int n;
		scanf("%d",&n);
		vector<long long > v;
		long long temp;
		char a;
		for(int i = 0 ; i < n ; i++){
			scanf("%d%c%d%c%d",&hh,&a ,&mm,&a,&tt);
			temp = hh*3600 + mm*60 + tt;
			v.push_back(temp);
		}
		scanf("%d",&I);
		if(n==0){
			printf("Case %d: 0\n",test);
			continue;
		}
		sort(v.begin() , v.end());
		queue<long long> q;
		int j = 0 , len = -1;
		q.push(v[j]);
		while(j<n){
			while(j< n && v[j] - q.front() < I){
				j++;
				q.push(v[j]);
			}
			int size = q.size() - 1;
			len = max(len , size);
			int temp = q.front();
			q.pop();
			while(!q.empty() && temp == q.front())
				q.pop();
		}
		printf("Case %d: %d\n",test ,len);
	}
}