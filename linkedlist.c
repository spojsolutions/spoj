#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *PTR;
};
void ins(struct node **);
int del(struct node **);
void display(struct node *);
int main()
{
	
	struct node *list;
	list=(struct node *)malloc(sizeof(struct node));
	list=NULL;
	point:
	printf("Enter the choice\n");
	printf("1->INSERT\n");
	printf("2->DELETE\n");
	printf("3->SHOW\n");
	printf("4->EXIT\n");
	int choice;
	scanf("%d",&choice);
	switch(choice)
	{
	case 1:
		ins(&list);
		break;
	case 2:
		printf("%d\n",del(&list));
		break;
	case 3:
		display(list);
		break;
	case 4:
		exit(1);
	default:
		printf("INVALID CHOICE PLEASE TRY AGAIN\n");
		break;
	}
	goto point;
	return 0;
}
void ins(struct node **nod)
{
	printf("Enter data of node\n");
	int info;
	scanf("%d",&info);
	struct node *temp;
	temp=(struct node *)malloc(sizeof(struct node));
	temp->data=info;
	if(*nod==NULL)
	{
		*nod=temp;
		temp->PTR=NULL;
	}
	else
	{
		temp->PTR=*nod;
		*nod=temp;
	}
}
int del(struct node **nod)
{
	int t;
	struct node *temp,*temp1;
	temp=(struct node *)malloc(sizeof(struct node));
	temp1=(struct node *)malloc(sizeof(struct node));
	if(*nod==NULL)
		return ;
	temp1=*nod;
	t=temp1->data;
	temp=temp1->PTR;
	*nod=temp;
	return t;
}
void display(struct node *nod)
{
	struct node *temp;
	temp=(struct node *)malloc(sizeof(struct node));
	temp=nod;
	while(temp!=NULL)
	{
		printf("%d\t",temp->data);
		temp=temp->PTR;
	}
}