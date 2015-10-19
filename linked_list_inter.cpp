/*
===================================================
Name :- Nishant Raj
Email :- raj.nishant360@gmail.com
College :- Indian School of Mines
Branch :- Computer Science and Engineering
Time :- 29 August 2015 (Saturday) 12:04
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
	node(){val = 0 , next = NULL;}
	node(int a , node * n){val = a , next = n;}
};
void print(node * a){
	while(a!=NULL){
		cout<<a->val<<" ";
		a = a->next;
	}
	cout<<endl;
}
node * insert(node * head , int val){
	node *temp = new node(val , head);
	return temp;
}
int cnt = 0;
node * merge_s(node * head){
	if(head == NULL)
		return NULL;
	node *fast , *slow;

	fast = head->next;
	slow = head;
	while(slow!=NULL &&fast!=NULL && fast->next!=NULL){
		slow = slow->next;
		fast = fast->next;
		if(fast!=NULL)
			fast = fast->next;
	}
	node *low = head;
	node *high = slow->next;
	slow->next = NULL;
	if(high == NULL)
		return low;
	node *left = NULL , *right =NULL;
	left = merge_s(low);
	right = merge_s(high);
	node *save = new node(0 , NULL);
	node *hold = save;
	while(left!=NULL && right!=NULL){
		if(left->val < right->val){
			save->next = left;
			left = left->next;
			save = save->next;
		} else{
			save->next = right;
			right = right->next;
			save = save->next;
		}
	}
	if(left==NULL)
		save->next = right;
	else
		save->next = left;
	return hold->next;
}
int main(){
	
	int n;
	cin>>n;
	node *head = NULL;
	for(int i = 0 ; i < n ; i++){
		int temp;
		cin>>temp;
		head = insert(head , temp);
	}
	print(head);
	print(merge_s(head));
	return 0;
}