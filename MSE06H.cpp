#include <bits/stdc++.h>
using namespace std;
struct par
{
    int f,s;
};
int tree[1009];
long long read(int pos)
{
    long long count = 0;
    while(pos)
    {
        count += tree[pos];
        pos -= (pos & -pos);
    }
    return count;
}
void update(int pos ,int MAX)
{
    while(pos <= MAX)
    {
        tree[pos]+=1;
        pos += (pos & -pos);
    }
}
bool compare(const par &a ,const par &b)
{
    return a.f == b.f ? a.s < b.s : a.f < b.f;
}
int main()
{
    int t;
    scanf("%d",&t);
    for(int l  =1 ; l<=t ; l++)
    {
        int n , m ,k ,a,b ;
        scanf("%d%d%d",&n,&m,&k);
        par p[1000009];
        memset(tree,0,sizeof tree);
        for(int i = 0; i < k ; i++){
            scanf("%d%d",&a , &b);
            p[i].f = a;
            p[i].s = b;
        }
        sort(p,p+k,compare);
        long long  res = 0;
        for(int i = 0 ; i < k ; i++)
        {
            res += (read(m) - read(p[i].s));
            update(p[i].s , m);
        }
        printf("Test case %d: %lld\n",l,res);
    }
    return 0;
}