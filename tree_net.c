#include <stdio.h>
#include <malloc.h>
#include <stdio.h>
 
typedef struct TREE
{
   int data;
   struct TREE *left;
   struct TREE *right;
} TREE;
 
int main()
{
  int data,depth;
  TREE *tree =NULL;
  TREE *InsertTree(int data,TREE *p);
  TREE *PrintTreeTriangle(TREE *tree, int level);
  int TreeDepth(TREE *tree,int *depth,int level);
  system("clear");
  while(1)
  {
	 printf("\nKey to insert|");
	 scanf("%d", &data);
	 if (data==0)
	  break;
	 tree =InsertTree(data,tree);
	 printf("\n Tree Display;\n");
	 PrintTreeTriangle(tree,1);
	 depth=0;
	 TreeDepth(tree,&depth,0);
	 printf("\nTree Depth =%d\n",depth);
 
	}
	return(0);
}
 
TREE *InsertTree(int data,TREE *p)
{
   if(!p)
 
	{
	  p=(TREE*)malloc(sizeof(TREE));
	  p->data=data;
	  p->left=NULL;
	  p->right=NULL;
	  return(p);
	 }
 
	if(data < p->data)
	p->left=InsertTree(data,p->left);
	else
	if(data > p->data)
	p->right=InsertTree(data,p->right);
	return(p);
 }
 
TREE *PrintTreeTriangle(TREE *tree, int level)
   {
	 int i;
	 if(tree)
	  {
		PrintTreeTriangle(tree->right,level+1);
		printf("\n\n");
		for(i=0;i<level;i++)
		printf("       ");
		printf("%d",tree->data);
		PrintTreeTriangle(tree->left,level+1);
	  }
	  return(NULL);
	}
 
 
int TreeDepth(TREE *tree,int *depth,int level)
{
  if(tree)
   {
     if (level>*depth)
     *depth=level;
     TreeDepth(tree->left,depth,level+1);
     TreeDepth(tree->right,depth,level+1);
     }
 
    return(0);
}