#include<stdio.h>
#include<algorithm>
#define MAX 33100
#define ll int
using namespace std ;
#define sf(n) finp(&n)
#define getcx getchar_unlocked
inline void finp(ll *a1 )
{
	ll n=0; int ch = getcx(); int sign = 1;
	while(ch < '0' || ch > '9')
	{
	if(ch == '-') sign=-1; ch = getcx();
	}
	while(ch >= '0' && ch <= '9')
	{
	n = (n << 3) + (n << 1) + ch - '0', ch = getcx();
	}
	*a1 = n * sign;
}
struct compression{
 int index,value;
}arr[MAX];
struct stu{
 int wt,num;
 struct stu *left,*right;
}*head[MAX];
int last=1,brr[MAX],crr[MAX];
struct stu *hNULL;

//for insert first element

void insert_first(struct stu *h,int x,int bit){
    h->wt=1;h->left=h->right=NULL;
    if(bit==-1) {h->num=x;return ;}
    if(x & (1<<bit))
      insert_first(h->right=(struct stu *)malloc(sizeof(struct stu )),x,bit-1);
    else
      insert_first(h->left=(struct stu *)malloc(sizeof(struct stu )),x,bit-1);
}

//insert for more than one element
void insert_last(struct stu *h1,struct stu *h2,int x,int bit){
if(h1!=NULL)
 h2->wt=h1->wt;
else
 h2->wt=0;
h2->wt++;
 if(bit==-1){h2->num=x;h2->left=h2->right=NULL;return ;}
 if(x & (1<<bit))
  {  if(h1!=NULL)
      {h2->left=h1->left;h1=h1->right;}
     else
        h2->left=NULL;
     insert_last(h1,h2->right=(struct stu *)malloc(sizeof(struct stu )),x,bit-1);
  }
 else
   {
      if(h1!=NULL)
       {h2->right=h1->right;h1=h1->left;}
      else
        h2->right=NULL;
      insert_last(h1,h2->left=(struct stu *)malloc(sizeof(struct stu )),x,bit-1);
   }
}
void insert_node(int x){
 if(last==1)
 {
     insert_first(head[1],x,14);
     return ;
 }
 insert_last(head[last-1],head[last],x,14);
}

//return number of element that is greater than x from 1 to y,where h points yth root
int fgreat(struct stu *h,int x,int bit){
int sum;
 if(h==NULL||bit==-1)
    return 0;
 if(x & (1<<bit))
 {
     return fgreat(h->right,x,bit-1);
 }
 else
 {
     if(h->right!=NULL)
        sum=h->right->wt;
     else
        sum=0;
     return sum+fgreat(h->left,x,bit-1);
 }
}

int find_great(int l,int r,int x){
if(l!=1)
 return fgreat(head[r],x,14)-fgreat(head[l-1],x,14);
else
 return fgreat(head[r],x,14);
}
bool cmp(struct compression a,struct compression b){
  return a.value<=b.value;
}

//same as lower_bound in c++
int l_bound(int i,int j,int x,int prev){
   if(i>j)
     return prev;
   int mid=(i+j)/2;
     if(x<=crr[mid])
        return l_bound(i,mid-1,x,mid);
     else
        return l_bound(mid+1,j,x,prev);
}

int main(){
 int t,x,i,j,as,l,r,n,y,bs;
 struct stu *temp=NULL;hNULL=NULL;
 sf(n);
 for(i=1;i<=n;i++){sf(x);arr[i].index=i;arr[i].value=x;}
 sort(arr+1,arr+n+1,cmp);
 for(i=1;i<=n;i++)
    crr[i]=arr[i].value;
 as=bs=1;
 
// this is coordinate compression ,since my algo is q*log(max value of arr[i].value) so i compressed it,since maximum number of element is n 
// output of this loop:if arr[] is-120 45 60 45 70 then it will be 5 1 3 1 4 
 for(i=1;i<=n;i++)
 {
    brr[arr[i].index]=as;
    if(i!=n&&arr[i].value!=arr[i+1].value)
        as+=bs,bs=1;
    else
        bs++;
 }
 
// for creating trie 
 for(i=1;i<=n;i++){
  x=brr[i];
   head[last]=(struct stu *)malloc(sizeof(struct stu ));head[last]->wt=0;
   insert_node(x);
   last++;
 }
  sf(t);
 while(t--)
 {
         sf(l);sf(r);sf(x);
         y=l_bound(1,n,x,n+1);//printf("%d ",y);
         if(x<crr[y])
            y--;
         printf("%d\n",find_great(l,r,y));
 }
 return 0;
}