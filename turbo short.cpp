#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int n,i;
    cin>>n;
    char A[n];
    for(i=0;i<n;i++)
    cin>>A[i];
    sort(A,A+n);
    for(i=0;i<n;i++)
    cout<<A[i]<<endl;
    return 0;
}
