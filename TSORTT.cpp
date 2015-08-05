#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
#define gc getchar_unlocked
inline void scanint(int &x)
{
    register int c = gc();
    x = 0;
    int neg = 0;
    for(;((c<48 || c>57) && c != '-');c = gc());
    if(c=='-') {neg=1;c=gc();}
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
    if(neg) x=-x;
}
typedef struct node Node;
struct node
{
	int data;
	struct node *LPTR;
	struct node *RPTR;
}*tree;
Node *create(int val)
{
	Node * temp;
	temp=(Node *)malloc(sizeof(Node));
	temp->data=val;
	temp->RPTR=NULL;
	temp->LPTR=NULL;
	return temp;
}
void add(Node **tr,int val)
{
	Node * temp;
	temp=(Node *)malloc(sizeof(Node));
	temp=*tr;
	if(temp==NULL)
	{
		(*tr)=create(val);
		return ;
	}
	if(val>=temp->data)
		add(&(temp->RPTR),val);
	else
		add(&(temp->LPTR),val);
}
void inorder(Node *tree)
{
	if(tree==NULL)
		return ;
	if(tree->LPTR!=NULL)
		inorder(tree->LPTR);
	printf("%d\n",tree->data);
	if(tree->RPTR!=NULL)
		inorder(tree->RPTR);
}
int main()
{
	tree=NULL;
	int N,i,val;
	scanf("%d",&N);
	for(i=0;i<N;i++)
	{
		scanint(val);
		add(&tree,val);
	}
	inorder(tree);
	return 0;
}