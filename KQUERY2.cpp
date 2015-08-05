#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    scanf("%d",&n);
    int sqr = int(sqrt(n));
    sqr+=5*sqr;
    int len = n/sqr + 1;
    int arr[len*sqr+9] , temp;
    memset(arr , 0 ,sizeof arr);
    int srt[len*sqr + 9];
    for(int i = 0 ; i < n ; i++){
        scanf("%d",&arr[i]);
        srt[i] = arr[i];
    }
    for(int i = n ; i<(n/sqr)*sqr ; i++)
        srt[i] = INT_MAX;
    for(int i = 0 , j = 0; i < len ;j+=sqr, i++)
        sort(srt+j , srt+j+sqr );
    int q;
    scanf("%d",&q);
    while(q--){
        int i , j , k;
        scanf("%d%d%d",&i,&j,&k);
        i-- , j--;
        int low = i/sqr;
        int up = (low + 1)*sqr;
        int count = 0;
        for(int ii = i ; ii <= min(up-1 , j) ; ii++)
            if(arr[ii] > k)
                count++;
        //cout<<"First -> "<<count<<endl;
        for(int ii = low+1 ; ii< j/sqr ; ii++ ){
            int pos = upper_bound(srt+ii*sqr , srt+ii*sqr + sqr , k) - (srt+ii*sqr);
            //cout<<"Upper Bound -> "<<pos<<endl;
            count+= (sqr - pos);
        }
        //cout<<"Second -> "<<count<<endl;
        for(int ii = max((j/sqr)*sqr , min(up-1 , j)+1) ; ii <= j ; ii++)
            if(arr[ii] > k)
                count++;
        //cout<<"Third -> "<<count<<endl;
        printf("%d\n",count);
    }
    return 0;
}