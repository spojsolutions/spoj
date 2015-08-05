#include<stdio.h>
#define MAX 5
struct QUEUE
{
	int A[MAX];
	int front,rear;
}Q;
void insert(int val)
{
	if(Q.rear>=MAX)
	{
		printf("ovreflow\n");
		Q.rear--;
		return ;
	}
	Q.A[Q.rear++]=val;
	if(Q.front==-1)
		Q.front=0;
}
int del()
{
	if(Q.front==-1)
	{
		printf("Underflow\n");
		return NULL;
	}
	int item=Q.A[Q.front];
	if(Q.front==Q.rear)
		Q.front=Q.rear=-1;
	else
		Q.front++;
	return item;
}
int main()
{
	printf("                         ENTER YOUR CHOICE\n");
	printf("                              1->INSERT\n");
	printf("                              2->DELETE\n");
	printf("                              3->EXIT\n");
	int choice,val;
	scanf("%d",&choice);
	switch(choice)
	{
		case 1:
		scanf("%d",&val);
		insert(val);
		break;
		case 2:
		printf("%d\n",del());
		break;
		case 3:
		exit(2);
		default:
		printf("WRONG ENTERY TRY AGAIN\n");
	}
	main();
	return 0;
}