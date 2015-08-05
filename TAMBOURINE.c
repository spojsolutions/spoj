#include<stdio.h>
#include<math.h>
#define RAD 0.0174532925
int main()
{

    while(1)
    {

        double R,angle=0,PI,r,N;
        PI=acos(-1);
        scanf("%lf%lf",&r,&N);
        if(r==0||N==0)
        break;
        N=2*N;
        angle=(((N-2)*PI)/(2*N));
        R=r/cos(angle);
        printf("%.2lf\n",R);

    }
    return 0;
}
