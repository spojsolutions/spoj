#include<stdio.h>
#include<stdlib.h>
#define MAX 10
int A[5][MAX];
int FRONT[5],REAR[5];
void insert(int val,int PR)
{
	int temp;
	temp=REAR[PR];
	if(REAR[PR]==MAX)
		REAR[PR]==0;
	else
		REAR[PR]++;
	if(REAR[PR]==FRONT[PR])
	{
		printf("OVERFLOW\n");
		REAR[PR]=temp;
		return ;
	}
	A[PR][REAR[PR]]=val;
	if(FRONT[PR]==-1)
		FRONT[PR]=0;
}
void del()
{
	int i,j;
	for(i=0;i<5;i++)
	{
		if(FRONT[i]!=-1&&REAR[i]!=-1){
			for(j=FRONT[i];FRONT[i]!=REAR[i];j++)
				printf("%d\t",A[i][j]);
			printf("\n");
		}
		else
			printf("EMPETY LIST OF PRIORITY %d\n",i);
	}
}
int main()
{
	int i;
	for(i=0;i<5;i++)
		FRONT[i]=REAR[i]=-1;
	printf("ENTER YOUR CHOICE\n");
	printf("1->INSERT\n");
	printf("2->DELETE\n");
	printf("3->EXIT\n");
	int choice,VAL,PR;
	scanf("%d",&choice);
	switch(choice)
	{
		case 1:
		printf("ENTER VALUE AND PRIORITY\n");
		scanf("%d%d",&VAL,&PR);
		insert(VAL,PR);
		break;
		case 2:
		del();
		break;
		case 3:
		exit(2);
		default:
		printf("INVALID OPTION\n");
	}
	main();
	return 0;
}