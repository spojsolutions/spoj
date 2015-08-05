#include<cstdlib>
#include<algorithm>
using namespace std;
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int number;
        scanf("%d",&number);
        char DES[number][100];
        int i,j,k=0;
        float angle[number];
        int time;
        for(i=0;i<number;i++)
        scanf("%s",DES[i]);
        scanf("%d",&time);
        char angl_char[number+1][7];
        for(i=0;i<number;i++)
        {
            j=0;
            while(DES[i][j]!='\0')
            {
                if((DES[i][j]>=48&&DES[i][j]<=57)||(DES[i][j]==46))
                {
                    angl_char[i][k]=DES[i][j];
                    k++;
                    angle[i]=atof(angl_char[i][k]);
                }
                j++;
            }
        }
        sort(angle,angle+number);
        int count=0,l=0,rev=0,q;
        float diff;
        while(count!=5&&l<number-1)
        {
            for(l=0;l<number-1;l++)
            {

                  diff=(angle[l]-anlge[l+1])*12;
                  if(diff!<=10)
                  coun++;

            }
            rev++;
        }
        printf("%d\n",rev*)
    }
    return 0;
}
