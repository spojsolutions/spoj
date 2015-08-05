#include <stdio.h>
#include <iostream>
#include <cmath>
#include <stdlib.h>
#include <bitset>
#include <map>
using namespace std;
bitset <1000009> p;
int size;
int prime[1000000];

 void sieve()
 {
 	size=0;
 	long long i,j;
 	p.set(0,1);
 	p.set(1,1);
 	prime[size++]=2;
 	for(i=3;i<1000001;i=i+2){
    	if(!p.test(i)){
       	 	prime[size++]=i;
        	for(j=i;j*i<1000001;j++){
            p.set(j*i,1);
        }
    }
}
}
/*struct node
{
	int data;
	struct node *LCHILD;
	struct node *RCHILD;
}*tree;
struct node *create(int val)
{
	struct node *temp;
	temp=(struct node*)malloc(sizeof(struct node));
	temp->data=val;
	temp->LCHILD=NULL;
	temp->RCHILD=NULL;
	return temp;
}
void add(struct node **tr,int val,int *count)
{
	struct node *copy,*copy1;
	copy=(struct node*)malloc(sizeof(struct node));
	copy1=(struct node*)malloc(sizeof(struct node));
	copy1=*tr;
	//if(val==copy1->data)
		//return;
	if(copy1==NULL)
	{
		(*count)++;
		*tr=create(val);
		return ;
	}
	if(val>copy1->data)
		add(&(copy1->RCHILD),val,count);
	else
		add(&(copy1->LCHILD),val,count);
}
void print_inorderR(struct node *tr)
{
	struct node *copy,*p;
	copy=(struct node*)malloc(sizeof(struct node));
	p=(struct node*)malloc(sizeof(struct node));
	copy=tr;
	if(copy==NULL)
	{
		return ;
	}
	if(copy->LCHILD!=NULL)
		print_inorderR(copy->LCHILD);
	printf("%d\n",copy->data);
	if(copy->RCHILD!=NULL)
		print_inorderR(copy->RCHILD);
}
void clear_tree(struct node **tree)
{
	if(*tree==NULL) return;
	clear_tree(&(*tree)->RCHILD);
	clear_tree(&(*tree)->LCHILD);
	*tree=NULL;
	free(*tree);
}*/
int main()
{
	int t;
	sieve();
	scanf("%d",&t);
	int c=1;
	while(t--)
	{
		int n,j;
		int p[1000009]={0};
		scanf("%d",&n);
		int i,check=0,count=0;
		long long temp;
		map<long long ,int >mp;
		map<long long,int> :: iterator t;
		for(i=0;i<n;i++)
		{
			scanf("%lld",&temp);
			for(j=0;(j<size) && (prime[j]*prime[j]<=temp);j++)
			{
				check=0;
				while(temp%prime[j]==0)
				{
					temp/=prime[j];
					check=1;
				}
				if(check)
					mp[prime[j]]=1;
			}
			if(temp>0 && temp!=1)
				mp[temp]=1;
		}
		printf("Case #%d: %d\n",c,mp.size());
    for(t=mp.begin();t!=mp.end();t++)
        printf("%lld\n",(*t).first);
        c++;
	}
	return 0;
}