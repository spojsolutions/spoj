/*
===================================================
Name :- Nishant Raj
Email :- raj.nishant360@gmail.com
College :- Indian School of Mines
Branch :- Computer Science and Engineering
Time :- 05 August 2015 (Wednesday) 15:25
===================================================*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair < int , int >
#define pb push_back
#define mp make_pair
#define mod 1000000009
class node{
public:
	int val;
	node *next;
	node(int v){val = v , next = NULL;}
};
node * insert(node *root , int val){
	if(root == NULL){
		root = new node(val);
		return root;
	}
	node *temp = new node(val);
	temp->next = root;
	return temp;
}
node *rev(node *root){
	if(root == NULL)
		return NULL;
	node *next = rev(root->next);
	if(next!= NULL)
		next->next = root;
	return next;
}
void print(node *root){
	node *temp = root;
	while(temp!=NULL){
		cout<<temp->val<<" ";
		temp = temp->next;
	}
	cout<<endl;
}
int main(){
	int n ;
	cin>>n;
	node *root = NULL;
	for(int i = 0 ; i < n ; i++){
		int temp;
		cin>>temp;
		root = insert(root , temp);
	}
	print(root);
	node *temp = rev(root);
	print(root);
	return 0;
}