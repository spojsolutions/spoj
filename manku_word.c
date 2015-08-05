#include<stdio.h>
#include<string.h>
int main()
{
    int i=0,n;
    scanf("%d",&n);
    while(i<n)
    {
        long long int number;
        char MANKU[10000]={"\0"};
        scanf("%lld",&number);
        long long int temp;
        int j=0,count;
       if((number/5)%5==0)
        {
            if(number%5==0)
            count=number/5;
            else
            count=number/5+1;
            number=number-count;
            while(number>0)
        {
             switch(number%5)
            {
                case 0:
                MANKU[j]='M';
                j++;
                break;
                case 1:
                MANKU[j]='A';
                j++;
                break;
                case 2:
                MANKU[j]='N';
                j++;
                break;
                case 3:
                MANKU[j]='K';
                j++;
                break;
                case 4:
                MANKU[j]='U';
                j++;
                break;
            }
            number=number/5;
        }}
        else{
        while(number>0)
        {
            switch(number%5)
            {
                case 1:
                MANKU[j]='M';
                j++;
                break;
                case 2:
                MANKU[j]='A';
                j++;
                break;
                case 3:
                MANKU[j]='N';
                j++;
                break;
                case 4:
                MANKU[j]='K';
                j++;
                break;
            }
            number=number/5;
        }

        }
        strrev(MANKU);
      printf("%s",MANKU);
      printf("\n");
        i++;
    }
    return 0;
}
