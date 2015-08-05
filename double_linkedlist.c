#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *prev;
	struct node *next;
};
void INS_BEG(struct node **,int );
void INS_POS(struct node **,int ,int );
void INS_LST(struct node **,int );
struct node *SEARCH(struct node *,int val);
void DEL_NODE(struct node **,int );
void DEL_BEG(struct node **);
void DEL_LST(struct node **);
void PRINT(struct node *);
void PRINT_L(struct node *);
void gotoxy(int x,int y);//position the cursor
int main()
{
	struct node *head;
	head=(struct node *)malloc(sizeof(struct node));
	head=NULL;
	system("clear");
	REPEAT:
	gotoxy(10,3);
	printf("ENTER YOUR CHOICE\n");
	gotoxy(10,4);
	printf("1->INSEART AT BEGNING\n");
	gotoxy(10,5);
	printf("2->INSEART AFTER CERTAIN NODE\n");
	gotoxy(10,6);
	printf("3->INSEART AT LAST\n");
	gotoxy(10,7);
	printf("4->DELETE FROM BEGNING\n");
	gotoxy(10,8);
	printf("5->DELETE CERTAIN NODE WITH SPECIFIC VALUE\n");
	gotoxy(10,9);
	printf("6->DELETE FROM END\n");
	gotoxy(10,10);
	printf("7->PRINT LINKED LIST \n");
	gotoxy(10,11);
	printf("8->PRINT LINKED LIST FROM LAST\n");
	gotoxy(15,13);
	printf("9->EXIT\n");
	int choice,val,info;
	scanf("%d",&choice);
	system("clear");
	switch(choice)
	{
		case 1:
		printf("ENTER THE VALUE OF NODE\n");
		scanf("%d",&val);
		INS_BEG(&head,val);
		break;
		case 2:
		printf("ENTER THE VALUE OF NODE\n");
		scanf("%d",&val);
		printf("ENTER THE VALUE OF NODE AFTER WHICH INSERTION IS TO BE DONE\n");
		scanf("%d",&info);
		INS_POS(&head,val,info);
		break;
		case 3:
		printf("ENTER THE VALUE OF NODE\n");
		scanf("%d",&val);
		INS_LST(&head,val);
		break;
		case 4:
		DEL_BEG(&head);
		break;
		case 5:
		printf("ENTER THE VALUE OF TO BE DELETED\n");
		scanf("%d",&val);
		DEL_NODE(&head,val);
		break;
		case 6:
		DEL_LST(&head);
		break;
		case 7:
		PRINT(head);
		break;
		case 8:
		PRINT_L(head);
		break;
		case 9:
		free(head);
		exit(13);
		default:
		gotoxy(20,17);
		printf("('_')YOU ENTERED WRONG CHOICE\n");
		gotoxy(25,18);
		printf("PLEASE TRY AGAIN");
	}
	goto REPEAT;
	return 0;
}
void INS_BEG(struct node **head,int val)//insert at begning
{
	struct node *temp,*copy;
	temp=(struct node *)malloc(sizeof(struct node));
	copy=(struct node *)malloc(sizeof(struct node));
	copy=*head;
	temp->data=val;
	temp->next=NULL;
	temp->prev=NULL;
	if(*head==NULL)
	{
		*head=temp;
		return ;
	}
	(*head)->prev=temp;
	temp->next=*head;
	*head=temp;
}
void INS_LST(struct node **head,int val)//insert at last
{
	struct node *temp,*copy,*save;
	temp=(struct node *)malloc(sizeof(struct node));
	copy=(struct node *)malloc(sizeof(struct node));
	save=(struct node*)malloc(sizeof(struct node));
	temp->data=val;
	copy=*head;
	if(*head==NULL)
	{
		*head=temp;
		copy->next=NULL;
		copy->prev=NULL;
		return ;
	}
	while(copy!=NULL)
	{
		save=copy;
		copy=copy->next;
	}
	save->next=temp;
	temp->prev=save;
	temp->next=NULL;
}
void INS_POS(struct node **head,int val,int pos)//insert node at certain position
{
	struct node *temp,*pre,*nex;
	temp=(struct node *)malloc(sizeof(struct node));
	pre=(struct node*)malloc(sizeof(struct node));
	nex=(struct node*)malloc(sizeof(struct node));
	temp->data=val;
	temp->next=NULL;
	temp->prev=NULL;
	pre=SEARCH(*head,pos);
	if(pre==NULL)
	{
		printf("NODE NOT FOUND\n");
		return ;
	}
	nex=pre->next;
	if(nex==NULL)
	{
		temp->prev=pre;
		pre->next=temp;
		return;
	}
	temp->next=pre->next;
	temp->prev=pre;
	nex->prev=temp;
	pre->next=temp;
}
struct node *SEARCH(struct node *head,int val)//search a particular node
{
	struct node *temp;
	temp=(struct node*)malloc(sizeof(struct node));
	temp=head;
	while(temp!=NULL)
	{
		if(temp->data==val)
			return temp;
		else
			temp=temp->next;
	}
	return NULL;
}
void DEL_NODE(struct node **head,int val)//delete node with specific value
{
	struct node *temp,*pre,*nex;
	temp=(struct node*)malloc(sizeof(struct node));
	pre=(struct node*)malloc(sizeof(struct node));
	nex=(struct node*)malloc(sizeof(struct node));
	if(*head==NULL)
	{
		printf("CAN'T PERFORM DELETE OPERATION\nLIST IS EMPTY\n");
		return ;
	}
	temp=SEARCH(*head,val);
	if(temp==NULL)
	{
		system("clear");
		gotoxy(10,14);
		printf("NODE NOT FOUND PLEASE TRY AGAIN\n");
		return ;
	}
	pre=temp->prev;
	if(temp->next==NULL)
	{
		system("clear");
		gotoxy(10,14);
		printf("%d\n",temp->data);
		temp->prev=NULL;
		pre->next=NULL;
		return ;
	}
	nex=temp->next;
	if(temp->prev==NULL)
	{
		system("clear");
		gotoxy(10,14);
		printf("%d\n",temp->data);
		temp->next=NULL;
		nex->prev=NULL;
		*head=nex;
		return ;
	}
	system("clear");
	gotoxy(10,14);
	printf("%d\n",temp->data);
	pre->next=temp->next;
	nex->prev=temp->prev;
	temp->next=NULL;
	temp->prev=NULL;
}
void DEL_BEG(struct node **head)//delete node from begning
{
	struct node *temp,*temp1;
	temp=(struct node*)malloc(sizeof(struct node));
	temp1=(struct node*)malloc(sizeof(struct node));
	if(*head==NULL)
	{
		system("clear");
		gotoxy(10,14);
		printf("CANT'T DELETE LIST IS EMPTY\n");
		return ;
	}
	temp=*head;
	temp1=temp->next;
	system("clear");
	gotoxy(10,14);
	printf("%d\n",temp->data);
	temp->next=NULL;
	temp1->prev=NULL;
	*head=temp1;
}
void DEL_LST(struct node **head)//delete node from last
{
	struct node *temp,*copy,*save;
	temp=(struct node*)malloc(sizeof(struct node));
	copy=(struct node*)malloc(sizeof(struct node));
	save=(struct node*)malloc(sizeof(struct node));
	save=NULL;
	copy=*head;
	if(copy==NULL)
	{
		system("clear");
		gotoxy(10,14);
		printf("CAN'T DELETE LIST IS EMPTY\n");
		return ;
	}
	while(copy->next!=NULL)
	{
		save=copy;
		copy=copy->next;
	}
	system("clear");//clear screen
	gotoxy(10,14);
	printf("%d\n",copy->data);
	copy->prev=NULL;
	temp=save;
	temp->next=NULL;
}
void gotoxy(int x,int y)//position the cursor
{
	printf("%c[%d;%df",0x1B,y,x);
}
void PRINT(struct node *head)//print linked list from begning
{
	struct node *temp;
	temp=(struct node*)malloc(sizeof(struct node));
	temp=head;
	gotoxy(10,17);
	while(temp!=NULL)
	{
		printf("%d\t",temp->data);
		temp=temp->next;
	}
	printf("\n");
}
void PRINT_L(struct node * head)//print linked list from last
{
	struct node * temp;
	temp=(struct node *)malloc(sizeof(struct node ));
	temp=head;
	while(temp->next!=NULL)
		temp=temp->next;
	gotoxy(10,17);
	while(temp!=NULL)
	{
		printf("%d\t",temp->data);
		temp=temp->prev;
	}
	printf("\n");
}