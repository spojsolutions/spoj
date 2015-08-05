#include <bits/stdc++.h>
using namespace std;
#define MAX 30001
int tree[30009];
void update(int pos){
    while(pos<=MAX){
        tree[pos]+=1;
        pos += (pos & -pos);
    }
}
int query(int pos){
    int result = 0;
    while(pos){
        result += tree[pos];
        pos -= (pos & -pos);
    }
    return result;
}
struct data{
    int value , pos;
};
struct query_data{
    int i , j , k , pos;
};
bool compare(const data &a , const data &b){
    return a.value > b.value;
}
bool cmp(const query_data &a , const query_data &b){
    return a.k > b.k;
}
int main(){
    int n;
    scanf("%d",&n);
    data arr[n+9];
    for(int i = 0 ; i < n ; i++)
        scanf("%d",&arr[i].value), arr[i].pos = i+1;
    sort(arr , arr+n , compare);
    int q_no;
    scanf("%d",&q_no);
    query_data q[q_no+9];
    for(int i = 0 ; i < q_no ; i++)
        scanf("%d%d%d",&q[i].i ,&q[i].j , &q[i].k) , q[i].pos = i;
    int result[q_no + 9];
    sort(q , q+q_no , cmp);
    int pos = 0;
    for(int i = 0 ; i<q_no ; i++){
        while(pos < n && arr[pos].value > q[i].k){
            update(arr[pos].pos);
            pos++;
        }
        result[q[i].pos] = query(q[i].j) - query(q[i].i - 1);
    }
    for(int i = 0 ; i < q_no ; i++)
        printf("%d\n",result[i]);
    return 0;
}