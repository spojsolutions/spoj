#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef tree<
int ,
null_type,
less<int>,
rb_tree_tag,
tree_order_statistics_node_update>pbd_set;
int main(){
    pbd_set s;
    int t;
    scanf("%d ",&t);
    while(t--){
        char typ;
        int n;
        scanf(" %c%d",&typ , &n);
        if(typ == 'I')
            s.insert(n);
        else if (typ == 'D')
            s.erase(n);
        else if (typ == 'K'){
            int ans;
            n--;
            if(s.find_by_order(n) != s.end()){
                ans = *s.find_by_order(n);
                printf("%d\n",ans);
            }
            else 
                printf("invalid\n");
        }
        else{
            int ans = s.order_of_key(n);
            printf("%d\n",ans);
        }
    }
    return 0;
}