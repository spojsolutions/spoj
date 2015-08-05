#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int i=1;
    while(1)
    {
        long long int A[4];
        int j;
        for(j=0;j<4;j++)
        cin>>A[j];
        sort(A,A+4);
        cout<<"Case "<<i<<": "<<A[2]+A[3]<<endl;
        i++;
    }
    return 0;
}
