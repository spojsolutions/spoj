#include <bits/stdc++.h>
using namespace std;
int n;
int cnt = 0;
char s[10];
void dfs(int x , int count){
	cnt++;
	s[count] = x + 48;
	count++;
	if(count < n) {
		for(int i = x+1 ; i < 10 ; i++)
			dfs(i , count);
	}
	cout<<s;
}
int main(){
	while(true){
		cin>>n;
		if(n==0)
			return 0;
			for(int i = 0 ; i < 10 ; i++){
				memset(s , 0 , sizeof s);
				for(int j = 0 ; j < n - 1 ; j++)
					cout<<char(i+48);
				dfs(i , 0);
				
			}
			if(n>1)
				for(int i = 0 ; i < n-1 ; i++)
					cout<<0;
		cout<<endl;
	}
	return 0;
}
