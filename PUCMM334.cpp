#include <stdio.h>
#include <iostream>
int main()
{
	int l;
	scanf("%d",&l);
	while(l--){
	long n,flage=1,countn=0,counto=0,i,a[10009];
	scanf("%ld",&n);
	long temp[10009]={0};
	for(i=0;i<n;i++)
	{
		scanf("%ld",&a[i]);
		if(a[i]<n)
			temp[a[i]]++;
		if(a[i]>=n)
			flage=0;
		if(a[i]==n-1)
			countn++;
		if(a[i]==0)
			counto++;
	}
	if(flage){
	if(counto==n){
		printf("0\n");
		continue;
	}
	if(countn==n)
	{
		printf("%ld\n",n);
		continue;
	}
	for(i=n-1;i>=0;i--)
	{
		if(temp[i]!=0)
			break;
	}
	if(temp[i-1]==i && temp[i]+i==n)
	{
		printf("%ld\n",i);
	}
	else
		printf("-1\n");
	}
	else
		printf("-1\n");
}
return 0;
}