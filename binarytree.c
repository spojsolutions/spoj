#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *LCHILD;
	struct node *RCHILD;
}*tree;
struct stack
{
	struct node *addr[100];
	int top;
}s,s1,s2;
void push(struct node *val,struct stack *temp)
{
	if(temp->top==99)
	{
		printf("overflow\n");
		return ;
	}
	temp->addr[++temp->top]=val;
}
struct node *pop(struct stack *temp)
{
	if(temp->top==-1)
	{
		printf("under flow\n");
		return NULL;
	}
	return temp->addr[temp->top--];
}
void add(struct node **,int val);//add node in binary tree
struct node *create(int val);//create node
void print_preorder(struct node *);//preorder traversal using stack
void print_inorderR(struct node *);//inorder traversal by recursion
void print_inorder(struct node *);//inorder traversal using stack
void print_postorder(struct node *tr);//postorder traversal using recursion
int main()
{
	tree=NULL;
	s.top=-1;
	s1.top=-1;
	s2.top=-1;
REPEAT:
	printf("ENTER YOUR CHOICE\n");
	printf("1->add node to tree\n");
	printf("2->print in postorder tree\n");
	printf("3->print in inorder traversal by rcursive method\n");
	printf("4->print in inorder through general method\n");
	printf("5->print in postorder through general method\n");
	printf("6->exit\n");
	int choice,val;
	scanf("%d",&choice);
	switch(choice)
	{
	case 1:
		scanf("%d",&val);
		add(&tree,val);
		break;
	case 2:
		print_preorder(tree);
		break;
	case 3:
		print_inorderR(tree);
		break;
	case 4:
		print_inorder(tree);
		break;
	case 5:
		print_postorder(tree);
		break;
	case 6:
		exit(1);
	default:
		printf("your choice is incorrect\n");
	}
	goto REPEAT;
	return 0;
}
struct node *create(int val)
{
	struct node *temp;
	temp=(struct node*)malloc(sizeof(struct node));
	temp->data=val;
	temp->LCHILD=NULL;
	temp->RCHILD=NULL;
	return temp;
}
void add(struct node **tr,int val)
{
	struct node *copy,*copy1;
	copy=(struct node*)malloc(sizeof(struct node));
	copy1=(struct node*)malloc(sizeof(struct node));
	copy1=*tr;
	if(copy1==NULL)
	{
		*tr=create(val);
		return ;
	}
	if(val>=copy1->data)
		add(&(copy1->RCHILD),val);
	else
		add(&(copy1->LCHILD),val);
}
void print_preorder(struct node *tree1)
{
	struct node *copy,*p;
	copy=(struct node*)malloc(sizeof(struct node));
	p=(struct node*)malloc(sizeof(struct node));
	copy=tree1;
	if(copy==NULL)
		printf("EMPTY TREE\n");
	else
		push(copy,&s);
	while(s.top>=0)
	{
		p=pop(&s);
		while(p!=NULL)
		{
			printf("%d\t",p->data);
			if(p->RCHILD!=NULL)
				push(p->RCHILD,&s);
			p=p->LCHILD;
		}
	}
	printf("\n");
}
void print_inorderR(struct node *tr)
{
	struct node *copy,*p;
	copy=(struct node*)malloc(sizeof(struct node));
	p=(struct node*)malloc(sizeof(struct node));
	copy=tr;
	if(copy==NULL)
	{
		printf("EMPTY TREE\n");
		return ;
	}
	if(copy->LCHILD!=NULL)
		print_inorderR(copy->LCHILD);
	printf("%d\t",copy->data);
	if(copy->RCHILD!=NULL)
		print_inorderR(copy->RCHILD);
}
void print_inorder(struct node *tr)
{
	struct node *p;
	p=(struct node*)malloc(sizeof(struct node));
	p=tr;
	push(NULL,&s1);
  step_2:
		while(p!=NULL)
		{
			push(p,&s1);
			p=p->LCHILD;
		}
		p=pop(&s1);
		while(p!=NULL)
		{
			printf("%d\t",p->data);

			if(p->RCHILD!=NULL)
			{
				p=p->RCHILD;
				goto step_2;
			}
			p=pop(&s1);
		}
}
void print_postorder(struct node *tr)
{
	struct node *p;
	p=(struct node*)malloc(sizeof(struct node));
	p=tr;
	if(p==NULL)
	{
		printf("empty tree\n");
		return;
	}
	if(p->LCHILD!=NULL)
		print_postorder(p->LCHILD);
	if(p->RCHILD!=NULL)
		print_postorder(p->RCHILD);
	printf("%d\t",p->data);
}
