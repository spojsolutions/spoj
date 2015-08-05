#include <stdio.h>
#include <iostream>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>
#include <climits>
#include <cfloat>
#include <map>
#include <fstream>
#include <sstream>
#include <bits/stdc++.h>
#include <climits>
using namespace std;
#define gc getchar_unlocked
inline void scanint(int &x)
{
    register int c = gc();
    x = 0;
    int neg = 0;
    for(;((c<48 || c>57) && c != '-');c = gc());
    if(c=='-') {neg=1;c=gc();}
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
    if(neg) x=-x;
}
class node
{
public:
	node * P;
	node * LCHILD;
	node * RCHILD;
	int value;
	int count;
}store[100009];
node *root= NULL;
int cnt=0;
int out[100009];
int loc=0;
node * create(node *parent,int val,bool check)
{
	if(root == NULL && parent == NULL)
	{
		root = &store[loc++];
		root->P = NULL;
		root->value = val;
		root->LCHILD= NULL;
		root->RCHILD= NULL;
		root->count= 1;
		return root;
	}
	node *temp=&store[loc++];
	if(check)
		parent->LCHILD = temp;
	else
		parent->RCHILD = temp;
	temp->P = parent;
	temp->value = val;
	temp->count = 1;
	temp->RCHILD = NULL;
	temp->LCHILD = NULL;
	while(temp->P != NULL)
	{
		temp->P->count++;
		temp= temp->P;
	}
	return temp;
}
void insert(int val,int pos)
{
	if(root == NULL	){
		root = create(NULL,val,false);
		return ;
	}
	bool check = true;
	node * temp =root;
	node *parent = NULL;
	while( temp != NULL)
	{
		parent = temp;
		if(temp->RCHILD != NULL)
		{
			if( pos  > (temp->RCHILD->count + 1))
			{
				pos-=(temp->RCHILD->count + 1);
				temp = temp->LCHILD;
				check = true;
			}
			else if(pos < (temp->RCHILD->count + 1))
			{
				temp = temp->RCHILD;
				check = false;
			}
		}
		else
		{
			if(pos >= 1)
			{
				pos-=1;
				temp = temp->LCHILD;
				check = true;
			}
			else if(pos < 1)
			{
				temp = temp->RCHILD;
				check = false;
			}
		}
	}
	create(parent , val, check);
}
void output(node *temp)
{
	if(temp->LCHILD != NULL)
		output(temp->LCHILD);
	out[temp->value] = cnt++;
	if(temp->RCHILD != NULL)
		output(temp->RCHILD);
}
int main()
{
	int t;
	scanint(t);
	for(int j=1;j<=t ; j++)
	{
		int a[100009];
		int n;
		scanint(n);
		bool flag=false;
		for(int i=0;i<n;i++){
			scanint(a[i]);
			if(a[i] > i)
				flag = true;
			insert(i,a[i]);}
		if(flag)
		{
			printf("Test : %d\n",j);
			printf("-1\n");
			continue;
		}
		output(root);
		root = NULL;
		cnt = 0;
		printf("Test : %d\n",j);
		for(int i=0;i<n;i++)
			printf("%d ",out[i] + 1);
		printf("\n");
	}
}