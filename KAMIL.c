#include<stdio.h>
int main(){int i=0;while(i<10){char WORD[21];scanf("%s",WORD);int j=0;
long long int mult=1;while(*WORD!='\0'){
if(*WORD=='T'||*WORD=='D'||*WORD=='L'||*WORD=='F')
mult=mult*2;WORD++;}printf("%lld\n",mult);i++;}return 0;}

