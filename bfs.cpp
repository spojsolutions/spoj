#include <iostream>
#include <stdio.h>
#define MAX 100
using namespace std;
struct queue
{
	int A[MAX];
	int rear,front;
}Q;
void insert(int val)
{
	if(Q.rear>=MAX)
	{
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
		return -5;
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
	Q.rear=-1;
	Q.front=-1;
	int n;
	cout<<"enter the number of vertices\n";
	cin>>n;
	int mat[n][n],status[n];
	for(int i=0;i<n;i++){
		status[i]=1;
		for(int j=0;j<n;j++)
			cin>>mat[i][j];
	}
	insert(0);
	status[0]=2;
	int k=del();
	while(k!=-5)
	{
		cout<<k<<endl;
		status[k]=3;
		for(int i=1;i<n;i++)
			if(mat[k][i]!=0 && status[i]==1){
				status[i]=2;
				insert(i);
			}
		k=del();
	}
	return 0;
}