#include <iostream>
#include <stdio.h>
#include <math.h>
#include <algorithm>
int main()
{
	int k,i,j,t,n,ch;
	printf("Enter the number of points in the dataset\n--->");
	scanf("%d",&n);
	float x[n],y[n],dis[n-1],avgdist=0.0,cnt=0.0,nnf,x1,y1,ratio;
	printf("Enter the coordinates of the points\n");
	for(i=0;i<n;i++)
	{
		printf("--->");
		scanf("%f%f",&x[i],&y[i]);
	}
	while(1)
	{
		printf("What do you want to do ?\n1. Enter a coordinate to find whether it is an outlier\n2. Exit\n--->");
		scanf("%d",&ch);
		if(ch==1)
		{
			t=0;avgdist=0.0;cnt=0.0;
			printf("Enter the coordinate of the point whose outlierness is to be detected\n--->");
			scanf("%f%f",&x1,&y1);
			printf("Enter the number of elements in the Nearest Neighbour(knn) Set\n--->");
			scanf("%d",&k);
			printf("Enter the value of threshold nnf ratio\n--->");
			scanf("%f",&ratio);
			for(i=0;i<n;i++)
			{
				if(x1==x[i] && y1==y[i])
					continue;
				else
				{
					dis[t]=sqrt((x1-x[i])*(x1-x[i])+(y1-y[i])*(y1-y[i]));
					t++;
				}
			}
			std::sort(dis,dis+t);
			for(i=0;i<k;i++)
			{
				avgdist=avgdist+dis[i];
			}
			avgdist=avgdist/k-1;
			for(i=0;i<k;i++)
			{
				nnf=dis[i]/avgdist;
				if(nnf>=ratio)
					cnt=cnt+1.0;
			}//printf("avgdist=%f\n",avgdist);
			if(cnt>=(0.66666*(k-1)))
				printf("Point (%.3f,%.3f) is an outlier\n",x1,y1);
			else
				printf("Point (%.3f,%.3f) is not an outlier\n",x1,y1);
		}
		else
			break;
	}
	return 0;
}