#include<stdio.h>
#include<malloc.h>
#include<time.h>
#include<stdlib.h>
#define MAX 123456
long A[1000005];
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
	time_t t1,t2;
	time(&t1);

	tree=NULL;
	int N,i,val;
	//scanf("%d",&N);
	for(i=0;i<MAX;i++)
	{
		//scanf("%d",&val);
		add(&tree,rand()%MAX);
	}
	inorder(tree);
	time(&t2);
	printf("%f\n",difftime(t2,t1));
	return 0;
}