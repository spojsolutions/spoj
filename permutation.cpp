#include <stdio.h>
#include <string.h>
#include <bits/stdc++.h>
using namespace std;
void swap(int *a, int *b) {
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void print(int a[], int i, int n) {
    int j;
    if(i == n) {
        for(int i = 0 ;  i<= n ;i++)
        printf("%d ", a[i]);
        cout<<endl;
    } else {
        for(j = i; j <= n; j++) {
            swap(a + i, a + j);
            print(a, i + 1, n);
            swap(a + i, a + j);
        }
    }
}

int main(void) {
    int  a[100];
    int n;
    cin>>n;
    for(int i = 0  ; i < n ; i++)
        cin>>a[i];
    print(a, 0, n - 1);
    return 0;
}