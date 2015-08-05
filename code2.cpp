#include <bits/stdc++.h>
using namespace std;
#define LL long long
LL po(LL a , LL n)
    {
    LL res = 1;
    for(int i = 0 ; i < n ; i++)
        res*=a;
    return res;
}
int main() {
    LL p , q , n;
    cin>>p>>q>>n;
    LL res =0 ;
    for(LL i = p ; i <= p+q ; i++)
        {
        LL temp = i;
        for(LL j = 1 ; j*j < temp ; j++)
            {
            if(temp % j == 0)
               {
                LL hold;
                 hold = po(j , n);
                if( temp%hold != 0)
                    res += 1;
                
                hold = po(temp / j , n);
                if(temp % hold !=0)
                    res += 1;
            }
            
        }
    }
    cout<<res<<endl;
    return 0;
}