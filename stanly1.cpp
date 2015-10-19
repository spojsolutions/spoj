/*
===================================================
Name :- Nishant Raj
Email :- raj.nishant360@gmail.com
College :- Indian School of Mines
Branch :- Computer Science and Engineering
Time :- 25 September 2015 (Friday) 21:48
===================================================*/
#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int arr[n+9];
        for(int i = 0 ; i < n ; i++){
            cin>>arr[i];
        }
        for(int i = 1 , j = n-2 ; i < n/2-1 ;j--, i++){
            if(arr[i-1]%2 ==0 && arr[i+1]%2==0)
            {
                if(abs(arr[j] - (arr[i-1] + arr[i+1])/2) > abs(arr[j] - arr[i]))
                    arr[i] = (arr[i-1] + arr[i+1])/2;
            }
        }
        int start = (n%2 == 0 ? n/2 : n/2 + 1);
        int start2 = n%2 == 0 ? start-1 : start-2;
        for(int i = start , j =start2  ; i < n-1 ;j--, i++){
            if(arr[i-1]%2 ==0 && arr[i+1]%2==0)
            {
                if(abs(arr[j] - (arr[i-1] + arr[i+1])/2) > abs(arr[j] - arr[i]))
                    arr[i] = (arr[i-1] + arr[i+1])/2;
            }
        }
        long long ans = 0;
        for(int i = 0 , j = n-1 ; i < n/2 ; i++ , j--)
            ans += abs(arr[i] - arr[j]);
        cout<<ans<<endl;
    }
    return 0;
}
