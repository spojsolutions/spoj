#include <bits/stdc++.h>
using namespace std;
struct cmp{
	bool operator()(const int &a , const int &b){
		return a>b;
	}
};
int main(){
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--){
		priority_queue<int> p;
		priority_queue<int , vector<int > , cmp> q;
		int n , hold=0 , l , r;
		while(true){
			cin>>n;
			if(n==0)
				continue;
			if(n!= -1){
				l = p.size() , r = q.size();
				if(l==r){
					if(n < hold){
						p.push(n);
						hold = p.top();
					}
					else{
						q.push(n);
						hold = q.top();
					}
				}
				else if (l < r){
					if(n > hold){
						p.push(q.top());
						q.pop();
						q.push(n);
					}
					else
						p.push(n);
					hold = p.top();
				}
				else if(l > r){
					if(n < hold){
						q.push(p.top());
						p.pop();
						p.push(n);
					}
					else
						p.push(n);
					hold = q.top();
				}
			}
			else if(n==-1){
				cout<<hold<<endl;

			}
		}
	}
	return 0;
}