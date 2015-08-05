#include<stdio.h>
#include<string.h>
int palin(char *num);
int main()
{
    int n,k=0;
    scanf("%d",&n);
    while(k<n)
    {
        char s[1000];
        scanf("%s",s);
        int j;
        j=palin(s);
        if(j==1)
        printf("yes\n");
        else printf("no\n");
        k++;
    }
    return 0;
}
int palin(char *num)
{
        int j,count=0;
        for(j=0;j<strlen(num)/2;j++)
        {
            if(*(num+j)==*(num+strlen(num)-1-j)){
                count++;}
                else return 0;
        }
        if(count==strlen(num)/2)
        return 1;
}
