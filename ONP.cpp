#include <stdio.h>
#include <stdlib.h>
#define MAX 1000
struct stack
{
    char p[1000];
	int top;
};
struct stack s;
void PUSH(char item)
{
	if(s.top==MAX-1)
		printf("Stack is full\n");
	s.top++;
	s.p[s.top]=item;
}
char POP()
{
	if(s.top==-1)
	{
		printf("Stack is empty\n");
		return NULL;
	}
	char temp;
	temp=s.p[s.top];
	s.top--;
	return temp;
}
int precidence(char temp)
{
	if(temp=='+'||temp=='-')
		return 1;
	if(temp=='*'||temp=='/')
		return 2;
	if(temp=='^')
		return 3;
	if((temp<=122&&temp>=97))
		return 4;
}
void strcat(char *target,char *source)
{
	while(*target!='\0')
		target++;
	while(*source!='\0')
	{
		*target=*source;
		target++;
		source++;
	}
}
int strlen(char *string)
{
	int count=0;
	while(*string!='\0')
	{
		count++;
		string++;
	}
	return count;
}
int main()
{
    int h=0,n;
	scanf("%d",&n);
	while(h<n){
	char Q[1000]={"\0"},output[1000]={"\0"},element;
	int i=0,j=0,flage,rank=0;

	scanf("%s",Q);
	strcat(Q,")");
	PUSH('(');
	while(Q[i]!='\0')
	{
		flage=1;
		if((Q[i]<=122&&Q[i]>=97))
		{
			output[j]=Q[i];
			j++;
		}
		if(Q[i]=='(')
		{
			PUSH('(');
		}

		if(Q[i]=='+'||Q[i]=='-'||Q[i]=='*'||Q[i]=='/'||Q[i]=='^')
		{
			while(flage==1)
			{
				element=POP();
				if(element=='+'||element=='-'||element=='*'||element=='/'||element=='^')
				{
					if(precidence(element)>=precidence(Q[i]))
					{
						output[j]=element;
						j++;
					}
					else
					{
						PUSH(element);
						flage=0;
						PUSH(Q[i]);
					}
				}
				else
				{
					PUSH(element);
					flage=0;
					PUSH(Q[i]);
				}
			}
		}
		if(Q[i]==')')
		{
			while(1)
			{
				element=POP();
				if(element=='(')
					break;
				else
				{
					output[j]=element;
					j++;
				}
			}
		}

		i++;
	}
h++;
	printf("%s\n",output);

fflush(stdin);


}
return 0;
}