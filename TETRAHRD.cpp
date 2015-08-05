#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define gc getchar_unlocked
class matrix
{
public:
    long long m[4][4];
};
matrix multiply(matrix a , matrix b)
{
    matrix temp;
    for(int i = 0 ; i < 4 ; i++)
        for(int j = 0 ; j < 4 ; j++)
        {
            temp.m[i][j] = 0;
            for(int k = 0 ; k < 4 ; k++){
                temp.m[i][j] = (temp.m[i][j] + a.m[i][k] *b.m[k][j]);
                if(temp.m[i][j] >= MOD) temp.m[i][j] %= MOD;
            }
        }
    return temp;
}
matrix arr[32];
void pre()
{
    arr[0].m[0][0] = 0 ; arr[0].m[0][1] = 0 ; arr[0].m[0][2]  = 0 ; arr[0].m[0][3] = 1;
    arr[0].m[1][0] = 1 ; arr[0].m[1][1] = 0 ; arr[0].m[1][2]  = 0 ; arr[0].m[1][3] = 1;
    arr[0].m[2][0] = 0 ; arr[0].m[2][1] = 1 ; arr[0].m[2][2]  = 0 ; arr[0].m[2][3] = 1;
    arr[0].m[3][0] = 0 ; arr[0].m[3][1] = 0 ; arr[0].m[3][2]  = 1 ; arr[0].m[3][3] = 1;
    matrix temp;
    for(int pos = 1 ; pos <= 29 ; pos++){
        for(int i = 0 ; i < 4 ; i++)
            for(int j = 0 ; j < 4 ; j++)
            {
                arr[pos].m[i][j] = 0;
                for(int k = 0 ; k < 4 ; k++){
                    arr[pos].m[i][j] = (arr[pos].m[i][j] + arr[pos-1].m[i][k] *arr[pos-1].m[k][j]);
                    if(arr[pos].m[i][j] >= MOD) arr[pos].m[i][j] %= MOD;
                }
            }
    }
}
matrix nth_Term(int n)
{
    int count = 0 ;
    matrix a;
    a.m[0][0] = 1 ; a.m[0][1] = 0 ; a.m[0][2] = 0 ; a.m[0][3]= 0;
    a.m[1][0] = 0 ; a.m[1][1] = 1 ; a.m[1][2] = 0 ; a.m[1][3]= 0;
    a.m[2][0] = 0 ; a.m[2][1] = 0 ; a.m[2][2] = 1 ; a.m[2][3]= 0;
    a.m[3][0] = 0 ; a.m[3][1] = 0 ; a.m[3][2] = 0 ; a.m[3][3]= 1;
    if(n<=2)
        return a;
    n-=2;
    while(n)
    {
        if(n&1){
            a = multiply(a,arr[count]);
        }
        count++;
        n>>=1;
    }
    return a;
}
int main()
{
    int t ;
    pre();
    scanf("%d",&t);
    matrix temp;
    long long res1 = 0 , res2 , n_1 , n_t , n_2 ;
    int m , n , res;
    long long inv = 333333336;
    while(t--)
    {
        scanf("%d%d", &m , &n);
        if(n == m)
        {
            temp = nth_Term(n);
            printf("%lld\n" , temp.m[3][2]);
            continue;
        }
        if(n<=2)
            res1 = 0;
        else
        {
            temp = nth_Term(n-1);
            n_1 = temp.m[3][2];
            temp = multiply(temp,arr[0]);
            n_t = temp.m[3][2];
            temp = multiply(temp,arr[1] );
            n_2 = temp.m[3][2];
            res1 = (n_2 + (n_t<<1) + n_1 -1);
            res1 = (res1*inv)%MOD;
        }
        if(m<=3)
            res2 = 0;
        else
        {
            m--;
            temp = nth_Term(m-1);
            n_1 = temp.m[3][2];
            temp = multiply(temp,arr[0]);
            n_t = temp.m[3][2];
            temp = multiply(temp,arr[1]);
            n_2 = temp.m[3][2];
            res2 = (n_2 +  (n_t<<1) + n_1 - 1 );
            res2 = (res2*inv)%MOD;
        }
        res = (res1 - res2 + MOD)%MOD;
        printf("%d\n",res);
    }
    return 0;
}