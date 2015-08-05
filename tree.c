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
struct node *peep(struct stack * temp)
{
	if(temp->top==-1)
		return NULL;
	return temp->addr[temp->top];
}
void add(struct node **,int val);//add node in binary tree
struct node *create(int val);//create node
void print_preorder(struct node *);//preorder traversal using stack
void print_inorderR(struct node *);//inorder traversal by recursion
void print_inorder(struct node *);//inorder traversal using stack
void print_postorder(struct node *tr);//postorder traversal using recursion
void print_postorderR(struct node *tr);//postorder traversal using stack/ itterative method
void printTree(struct node *tree,int level);//print tree triangle
void caseB(struct node **tree,struct node *loc,struct node * ploc);//case A of deletion when node have both child
void caseA(struct node **tree,struct node * loc,struct node *ploc);//case B of deletion when node have one or no child
void delete_Node(struct node ** tree,int val);//delete node from tree
struct node *search_P(struct node *tree,int val);//search parent of node
struct node *search(struct node *tree,int val);//search node of tree
void clear_tree(struct node **);
int main()
{
	tree=NULL;
	s.top=-1;
	s1.top=-1;
	s2.top=-1;
REPEAT:
	printf("\n\n\nENTER YOUR CHOICE\n");
	printf("1->add node to tree\n");
	printf("2->print in preorder tree\n");
	printf("3->print in inorder traversal by rcursive method\n");
	printf("4->print in inorder through itterative method\n");
	printf("5->print in postorder through recursive method\n");
	printf("6->print in postorder by itterative method\n");
	printf("7->delete a node from tree\n");
	printf("8->clear all node of tree\n");
	printf("9->exit \n");
	int choice,val;
	scanf("%d",&choice);
	system("clear");
	switch(choice)
	{
	case 1:
		scanf("%d",&val);
		add(&tree,val);
		printTree(tree,1);
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
		print_postorderR(tree);
		break;
	case 6:
		print_postorder(tree);
		break;
	case 7:
	    printf("enter the value of node to be deleted\n");
	    scanf("%d",&val);
	    delete_Node(&tree,val);
	    break;
	case 8:
		clear_tree(&tree);
		break;
	case 9:
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
void print_postorderR(struct node *tr)
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
		print_postorderR(p->LCHILD);
	if(p->RCHILD!=NULL)
		print_postorderR(p->RCHILD);
	printf("%d\t",p->data);
}
void print_postorder(struct node *root)
{
	if(root==NULL)
		return;
	do
	{
		while(root!=NULL)
		{
			if(root->RCHILD!=NULL)
				push(root->RCHILD,&s2);
			push(root,&s2);
			root=root->LCHILD;
		}
		root=pop(&s2);
		if(root->RCHILD!=NULL && root->RCHILD==peep(&s2))
		{
			pop(&s2);
			push(root,&s2);
			root=root->RCHILD;
		}
		else
		{
			printf("%d\t",root->data);
			root=NULL;
		}
	}while(s2.top!=-1);
}
void printTree(struct node *tree,int level)
{
	int i;
	if(tree!=NULL)
	{
		printTree(tree->RCHILD,level+1);
		printf("\n");
		for(i=0;i<level;i++)
			printf("   ");
		printf("%d",tree->data);
		printTree(tree->LCHILD,level+1);
	}
}
struct node *search(struct node *tree,int val)
{
	struct node *temp;
	temp=(struct node *)malloc(sizeof(int));
	if(tree==NULL)
		return NULL;
	if(tree->data==val)
		return tree;
	else if(tree->data<val)
		return search(tree->RCHILD,val);
	else
		return search(tree->LCHILD,val);
}
struct node *search_P(struct node *tree,int val)
{
	struct node *save,*temp;
	temp=(struct node *)malloc(sizeof(struct node));
	save=(struct node *)malloc(sizeof(struct node));
	temp=tree;
	save=tree;
	if(temp->data==val)
		return NULL;
	else if(val>temp->data)
		temp=temp->RCHILD;
	else
		temp=temp->LCHILD;
	while(temp!=NULL)
	{
		if(temp->data==val)
			return save;
		else if(val>temp->data){
			save=temp;
			temp=temp->RCHILD;}
		else{
			save=temp;
			temp=temp->LCHILD;}
	}
	return NULL;
}
void delete_Node(struct node ** tree,int val)
{
	struct node *loc,*ploc,*temp;
	loc=(struct node  *)malloc(sizeof(struct node));
	ploc=(struct node  *)malloc(sizeof(struct node));
	temp=(struct node  *)malloc(sizeof(struct node));
	temp=*tree;
	if(*tree==NULL)
		return ;
	loc=search(temp,val);
	if(loc==NULL)
	{
		printf("NODE NOT FOUND\n");
		return ;
	}
	ploc=search_P(temp,val);
	if(loc->RCHILD!=NULL && loc->LCHILD!=NULL)
		caseB(tree,loc,ploc);
	else
		caseA(tree,loc,ploc);
}
void caseA(struct node **tree,struct node * loc,struct node *ploc)
{
	struct node *child;
	child=(struct node *)malloc(sizeof(struct node));
	printf("deleted node=%d\n",loc->data);
	if(loc->RCHILD==NULL && loc->LCHILD==NULL)
		child=NULL;
	else if(loc->RCHILD==NULL)
		child=loc->LCHILD;
	else 
		child=loc->RCHILD;
	if(ploc!=NULL){
		if(ploc->RCHILD==loc)
			ploc->RCHILD=child;
		else
			ploc->LCHILD=child;}
	else
		(*tree)=child;
}
void caseB(struct node **tree,struct node *loc,struct node * ploc)
{
	struct node *suc,*par_suc;
	suc=(struct node*)malloc(sizeof(struct node));
	par_suc=(struct node*)malloc(sizeof(struct node));
	printf("deleted node=%d\n",loc->data);
	suc=loc->RCHILD;
	par_suc=loc;
	while(suc->LCHILD!=NULL)
	{
		par_suc=suc;
		suc=suc->LCHILD;
	}
	caseA(tree,suc,par_suc);
	if(ploc!=NULL)
	{
		if(loc==ploc->RCHILD)
			ploc->RCHILD=suc;
		else
			ploc->LCHILD=suc;
	}
	else
		(*tree)=suc;
	suc->LCHILD=loc->LCHILD;
	suc->RCHILD=loc->RCHILD;
}
void clear_tree(struct node **tree)
{
	if(*tree==NULL) return;
	clear_tree(&(*tree)->RCHILD);
	clear_tree(&(*tree)->LCHILD);
	*tree=NULL;
	free(*tree);
}