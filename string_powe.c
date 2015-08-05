#include<stdio.h>
#include<string.h>
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        char A[1000000],B[1000000];
        scanf("%s",A);
        scanf("%s",B);
        int flage=1,i=0;
        int len_A=strlen(A),len_B=strlen(B);
        if(len_B>len_A)
        {
            if(len_B%len_A==0)
            {
                while(A[i]!='\0')
                {
                    if(A[i]!=B[i]){
                    flage=0;
                    break;
                    }
                    i++;

                }

            }
        }
        else
        {
            if(len_A%len_B==0)
            {
                while(B[i]!='\0')
                {
                    if(B[i]!=A[i]){
                    flage=0;
                    break;
                    }
                    i++;

                }

            }
        }
        if(flage==0)
        printf("NO\n");
        else
        printf("YES\n");

    }
    return 0;
}
