#include<stdio.h>
#include<stdlib.h>
typedef struct node NODE;
struct node 
{
	int data;
	struct node *prev;
	struct node *next;
};
NODE * create(int val)
{
	NODE *temp;
	temp=(NODE *)calloc(1,sizeof(NODE));
	temp->data=val;
	temp->prev=NULL;
	temp->next=NULL;
	return temp;
}
void insert_beg(NODE **N,int val)
{
	NODE *temp,*temp1;
	temp1 = *N;
	temp=(NODE *)malloc(1*sizeof(NODE));
	temp=create(val);
	if(temp1==NULL){
		*N=temp;
		return ;
	}
	temp->next=temp1;
	temp1->prev=temp;
	temp->prev=NULL;
	*N=temp;
}
NODE *del_beg(NODE **N)
{
	NODE * temp,*temp1;
	temp1=(NODE *)malloc(sizeof(NODE));
	temp=(NODE *)malloc(sizeof(NODE));
	temp=*N;
	if(temp==NULL)
		return NULL;
	temp1=temp;
	temp=temp->next;
	temp->prev=NULL;
	return temp1;
}
int main()
{
	NODE *head,*temp;
	head=(NODE *)malloc(sizeof(NODE));
	temp=(NODE *)malloc(sizeof(NODE));
	head=NULL;
	START:
	printf("ENTER YOUR CHOICE\n");
	printf("1->INSERT AT BEGNIBG\n");
	printf("2->DELETE AT BEGNING\n");
	printf("3->EXIT\n");
	int choice,val;
	scanf("%d",&choice);
	switch(choice)
	{
		case 1:
		scanf("%d",&val);
		insert_beg(&head,val);
		break;
		case 2:
		temp=del_beg(&head);
		if(temp==NULL)
			printf("EMPTY LIST\n");
		else
			printf("%d\n",temp->data);
		break;
		case 3:
		exit(1);
		default:
		printf("INVALID CHOICE PLEASE TRY AGAIN\n");
	}
	goto START;
	return 0;
}