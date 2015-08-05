#include<stdio.h>
void quicksort(int x[10],int first,int last);
int main()
{
    int A[10],DIFF1[10],DIFF2[10];
    int i,j=0,k=0;
    for(i=0;i<10;i++)
    {
    scanf("%d",&A[i]);
    if(100-A[i]<0){
    DIFF1[j]=100-A[i];j++;}
    else{
    DIFF2[k]=100-A[i];k++;}
   }
    quicksort(DIFF1,0,j-1);
    quicksort(DIFF2,0,k-1);
    if(DIFF2[0]<=-(DIFF2[j-1]))
    printf("%d",100+DIFF2[0]);
    else
    printf("%d",100-DIFF1[j-1]);
    return 0;
}
void quicksort(int x[10],int first,int last){
    int pivot,j,temp,i;

     if(first<last){
         pivot=first;
         i=first;
         j=last;

         while(i<j){
             while(x[i]<=x[pivot]&&i<last)
                 i++;
             while(x[j]>x[pivot])
                 j--;
             if(i<j){
                 temp=x[i];
                  x[i]=x[j];
                  x[j]=temp;
             }
         }

         temp=x[pivot];
         x[pivot]=x[j];
         x[j]=temp;
         quicksort(x,first,j-1);
         quicksort(x,j+1,last);

    }
}
