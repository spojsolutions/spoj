#include<iostream>
using namespace std; main(){int t;cin>>t;while(t--){int n,i,P=0,Q=0;cin>>n;int A[n];for(i=0;i<n;i++){cin>>A[i];if(i%2==0&&A[i]<0)Q-=A[i];else if(A[i]>0)P+=A[i];}if(P>=Q)cout<<"Some Mirrors Lie!";else cout<<"Every Girl Lies!";}}
