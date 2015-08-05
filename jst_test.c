#include<stdio.h>
#include<stdlib.h>
void main()
{
   int i=0,j;
  scanf("%d",&j);
  while(i<j)
  {
    int dim;
    int *arr;
    scanf("%d",&dim);
    arr=(int *)malloc(dim*dim*sizeof(int));
    int k,l;
    for(k=0;k<dim;k++)
      for(l=0;l<dim;l++)
      scanf("%d",arr+k*dim+l);
    int temp=dim;
    for(k=0;k<dim;k++)
    {
      for(l=0;l<dim;l++)
   	  {
        printf("%d\t",*(arr+(dim*(dim-1)+k)-l*dim));
      }
      printf("\n");
    }
    i++;
  }
  return 0;
}
