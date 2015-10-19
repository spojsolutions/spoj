/*
===================================================
Name :- Nishant Raj
Email :- raj.nishant360@gmail.com
College :- Indian School of Mines
Branch :- Computer Science and Engineering
Time :- 11 September 2015 (Friday) 15:05
===================================================*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair < int , int >
#define pb push_back
#define mp make_pair
#define mod 1000000009
template < class T >
class Trie{
public:
	Trie(){
		root = new T;
	}
	void insert(int num){
		T * temp = root;
		for(int i = 31 ; i>= 0 ; i--){
			if(num&(1<<i)){
				if(temp->right == NULL){
					temp->right = new T;
				}
				temp = temp->right;
			}else{
				if(temp->left ==NULL)
					temp->left = new T;
				temp = temp->left;
			}
		}
	}
	int query(int num){
		T *temp = root;
		int ans = 0;
		for(int i = 31 ; i>= 0 ; i--){
			if(num&(1<<i)){
				if(temp->left!= NULL)
					temp = temp->left , ans = (ans | (1<<i));
				else if(temp->right!= NULL)
					temp = temp->right;
			} else{
				if(temp->right != NULL)
					temp = temp->right , ans |= (1<<i);
				else if(temp->left != NULL)
					temp = temp->left;
			}
		}
		return ans;
	}
private:
	T *root;
};
class node{
public:
	node *left , *right;
	node(){left = NULL , right = NULL;}
};
int main(){
	
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int arr[n+9];
		for(int i = 0 ; i < n ; i++)
			cin>>arr[i];
		Trie<node> tree;
		int a= 0 , ans = 0;
		tree.insert(0);
		for(int i = 0 ; i < n ; i++){
			a = a^arr[i];
			tree.insert(a);
			ans = max(ans , tree.query(a));
		}
		cout<<ans<<endl;
	}
	
	return 0;
}