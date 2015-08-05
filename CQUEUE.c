#include<stdio.h>
#define MAX 5
struct CQUEUE
{
	int A[MAX];
	int front ,rear ;
}*CQ;
void insert(int val)
{
	int temp=CQ->rear;
	if(CQ->rear==MAX)
		CQ->rear=0;
	else
		CQ->rear++;
	if(CQ->rear == CQ->front)
	{
		printf("OVERFLOW\n");
		CQ->rear=temp;
	}
	CQ->A[CQ->rear]=val;
	if(CQ->front==-1)
		CQ->front=0;
}
char* del()
{
	if(CQ->front==-1)
	{
		return "UNDERFLOW\n";
	}
	char item[10];
	int i=0,r,temp=CQ->A[CQ->front];
	while(temp)
	{
		item[i]=temp%10;
		temp=temp/10;
		i++;
	}
	item[i]='\0';
	if(CQ->rear==CQ->front)
		CQ->rear=CQ->front=-1;
	if(CQ->front==MAX)
		CQ->front=0;
	else
		CQ->front++;
	return item;
}
int main()
{
	CQ->rear=-1;
	CQ->front=-1;
	printf("ENTER YOUR CHOICE\n");
	printf("1->INSERT\n");
	printf("2->DELETE\n");
	printf("3->EXIT\n");
	int choice,val;
	scanf("%d",&choice);
	switch(choice)
	{
		case 1:
		scanf("%d",&val);
		insert(val);
		break;
		case 2:
		printf("%s\n",del());
		break;
		case 3:
		exit(2);
		default:
		printf("INVALID choice\n");
	}
	main();
	return 0;
}