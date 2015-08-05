#include<stdio.h>
#include<string.h>
int main()
{
    int t;
    scanf("%d",&t);
    while(t--){
	char S[10000],A[10000],C[100000]={"0"},B[10000];
    int i=0,temp1=0,temp2=0,temp3=0,size=0,size2=0,j,k=0,temp4=0,temp5=0,carry=0,t;
    scanf("%s",S);
    scanf("%s",B);
    while(S[i]!='\0')
    {
        size++;
        i++;
		C[k]='0';
		k++;
    }
	i=0;
    while(B[i]!='\0')
    {
        size2++;
        i++;
		C[k]='0';
		k++;
    }
	for(j=size2-1;j>=0;j--){
    for(i=size-1;i>=0;i--)
    {
        temp1=(S[i]-48)*(B[j]-48);
        temp2=(temp1+temp3)%10;
        temp3=(temp1+temp3)/10;
		A[size -1-i]=temp2+48;
	}
	A[size]=temp3+48;
	temp3=0;
	for(i=size;i>=0;i--)
	{
		temp4=(A[size-i]-48)+(C[(size2-1-j)+(size-i)]-48);
		temp5=(temp4+carry)%10;
		carry=(temp4+carry)/10;
		C[(size2-1-j)+(size-i)]=temp5+48;
	}
	}
	if(carry!=0)
	C[size2+size]=carry+48;
	i=0;
	while(C[k-1-i]<=48){
		C[k-1-i]='\0';i++;}
	if(carry!=0)
		for(i=size2+size;C[i]!='\0';i--)
			printf("%c",C[i]);
	else
		for(i=size2+size-1;C[i]!='\0';i--)
			printf("%c",C[i]);
    }
	return 0;
}
