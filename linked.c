#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
};
void INS_BEG(struct node **head,int data);
void INS_POS(struct node **head,int data,int info);
void INS_LST(struct node **head,int data);
struct node *SEARCH(struct node *head,int info);
void PRINT(struct node *head);
void DEL_NODE(struct node **head,int info);
int main()
{
	struct node *head;
	head=(struct node *)malloc(sizeof(struct node));
	head=NULL;
	REPEAT:
	printf("\n\n\n\n");
	printf("                  | ENTER YOUR CHOICE |                \n");
	printf("             _____|___________________|______          \n");
	printf("             | 1->INSERT AT BEGNING OF LIST |          \n");
	printf("             |______________________________|          \n");
	printf("             | 2->INSERT AT CERTAIN POSITION|          \n");
	printf("             |______________________________|          \n");
	printf("             | 3->INSERT AT LAST OF LIST    |          \n");
	printf("             |______________________________|          \n");
	printf("             | 4->DELETE NODE               |          \n");
	printf("             |______________________________|          \n");
	printf("             |  5->PRINT LIST               |          \n");
	printf("             |______________________________|          \n");
	printf("             | 6->EXIT                      |          \n");
	printf("             |______________________________|          \n");
	int choice,val,pos;
	scanf("%d",&choice);
	switch(choice)
	{
		case 1:
		printf("              ENTER THE VALUE OF NODE\n");		
		scanf("%d",&val);
		INS_BEG(&head,val);
		break;
		case 2:
		printf("              ENTER THE VALUE OF NODE\n");
		scanf("%d",&val);
		printf("              ENTER THE VALUE OF NODE\n");
		printf("              AFTER WHICH NODE IS TO BE INSERTED\n");
		scanf("%d",&pos);
		INS_POS(&head,val,pos);
		break;
		case 3:
		printf("              ENTER THE VALUE OF NODE\n");
		scanf("%d",&val);
		INS_LST(&head,val);
		break;
		case 4:
		printf("              ENTER THE VALUE OF NODE TO BE DELETED\n");
		scanf("%d",&val);
		DEL_NODE(&head,val);
		break;
		case 5:
		PRINT(head);
		break;
		case 6:
		free(head);
		exit(1);
		break;
		default:
		printf("               YOU ENTERED WRONG CHOICE\n");
		printf("               PLEASE TRY AGAIN\n");
	}
	goto REPEAT;
	return 0;
}
void INS_BEG(struct node **head,int val)
{
	struct node *temp;
	temp=(struct node *)malloc(sizeof(struct node));
	temp->data=val;
	if(*head==NULL)
	{
		*head=temp;
		temp->next=NULL;
	}
	else
	{
		temp->next=*head;
		*head=temp;
	}
}
void INS_POS(struct node **head,int val,int info)
{
	struct node *temp,*pre,*copy;
	temp=(struct node *)malloc(sizeof(struct node));
	pre=(struct node *)malloc(sizeof(struct node));
	temp->data=val;
	pre=SEARCH(*head,info);
	if(pre==NULL)
	{
		printf("VALUE NOT FOUND \n");
		return ;
	}
	if(pre->next==NULL)
	{
		temp->next=NULL;
		pre->next=temp;
		return ;
	}
	temp->next=pre->next;
	pre->next=temp;
}
void INS_LST(struct node **head,int val)
{
	struct node *temp,*pre,*save;
	temp=(struct node *)malloc(sizeof(struct node));
	pre=(struct node *)malloc(sizeof(struct node));
	save=(struct node *)malloc(sizeof(struct node));
	temp->data=val;
	pre=*head;
	if(*head==NULL)
	{
		*head=temp;
		temp->next=NULL;
		return ;
	}
	while(pre!=NULL)
	{
		save=pre;
		pre=pre->next;
	}
	save->next=temp;
	temp->next=NULL;
}
struct node * SEARCH(struct node *head ,int val)
{
	if(head==NULL)
	{
		printf("EMPTY LINKED LIST\n");
		return NULL;
	}
	struct node *temp;
	temp=(struct node *)malloc(sizeof(struct node));
	temp=head;
	while(temp!=NULL)
	{
		if(val==temp->data)
			return temp;
		else
			temp=temp->next;
	}
	return NULL;
}
void DEL_NODE(struct node **head,int val)
{
	struct node *temp,*temp1,*save;
	temp=(struct node *)malloc(sizeof(struct node));
	temp1=(struct node *)malloc(sizeof(struct node));
	save=(struct node *)malloc(sizeof(struct node));
	temp=*head;
	if(SEARCH(*head,val)==NULL)
	{
		printf("NO SUCH VALUE EXITS IN LINKED LIST\n");
		return ;
	}
	if(temp->data==val)
	{
		*head=temp->next;
		return ;
	}
	while(temp!=NULL)
	{
		save=temp;
		if(temp->next->data==val)
		{
			temp1=temp->next;
			break;
		}
		else
			temp=temp->next;
	}
	if(temp1==NULL)
	{
		save->next==NULL;
		return ;
	}
	save->next = temp1->next;
}
void PRINT(struct node *head)
{
	struct node *temp;
	temp=(struct node *)malloc(sizeof(struct node));
	temp=head;
	while(temp!=NULL)
	{
		printf("%d\t",temp->data);
		temp=temp->next;
	}
}