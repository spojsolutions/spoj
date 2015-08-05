#include <stdio.h>
#include <cmath>
using namespace std;
int num[6001]={0},prime[800],prime_index=0;

int main()
{
    int i,j,n,t,temp,diff,k;

    scanf("%i",&t);

    prime[0]=2;

    for(i=3;    i<78;   i+=2)
        if(!num[i])
        {
            prime[++prime_index] = i;
            for(j=i*i, k = i<<1;    j <= 6000;  j+=k)
                num[j] = 1;
        }

    for(;   i<=6000;    i+=2)
        if(!num[i])
            prime[++prime_index] = i;

    while(t--)
    {
        scanf("%i",&i);

        j=0;

        while(i/(int)pow(10,j))
            j++;

        switch(j)
        {
            case 1: j = 9-2*i;
                    break;
            case 2: j = 99 - 2*i;
                    break;
            case 3: j = 999 - 2*i;
                    break;
            case 4: j = 9999 - 2*i;
                    break;
            case 5: j = 99999 - 2*i;
                    break;
            case 6: j = 999999 - 2*i;
                    break;
            case 7: j = 9999999 - 2*i;
                    break;
            case 8: j = 99999999 - 2*i;
                    break;
            case 9: j = 999999999 - 2*i;
                    break;
        }

        diff = abs(j);

        if(diff == 1)
            printf("-1\n");

        else
        {
            for(i=0;    i<= prime_index;    i++)
                if(diff%prime[i]==0)
                {
                    printf("%i\n",prime[i]);
                    break;
                }

            if(i == prime_index+1)
                printf("%i\n",diff);
        }

    }
    return 0;
}