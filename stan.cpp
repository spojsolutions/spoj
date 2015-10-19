#include <bits/stdc++.h>
using namespace std;
class node{
public:
 int val , height , sum , num;
 node * left , *right;
    node(){
        val = height = sum = 0;
        left = right = NULL;
    }
};
int get_sum(node *x){
    
    if(x == NULL)
        return 0;
    return x->sum;
}
node *get_new_node(int key , int val){

    node *temp = new node();
    temp->val =  key;
    temp->left = NULL;
    temp->right = NULL;
    temp->height = 1;
    temp->sum = 1;
    temp->num = val;
    return temp;
}

bool find(int key , node *root){
 
 if(root == NULL)
  return false;
 if(key < root->val)
  return find(key , root->left);
 else if(key > root->val)
  return find(key , root->right);
 else
  return true;
}

int get_height(node *x){
 
 if(x==NULL)
  return 0;
 return x->height;
}

int get_diff(node *x){

    if(x == NULL)
        return 0;
    return get_height(x->left) - get_height(x->right);
}
node *left_rotate(node *x){
 
 node *y  = x->right;
 node *y_left = y->left;

 y->left = x;
 x->right = y_left;

 x->height = max(get_height(x->left) , get_height(x->right)) + 1;
    x->sum = get_sum(x->left) + get_sum(x->right) + 1;
    y->height = max(get_height(y->left) , get_height(y->right)) + 1;
    y->sum = get_sum(y->left) + get_sum(y->right) + 1;
    return y;
}

node *right_rotate(node *x){

    node *y = x->left;
    node *y_right = y->right;

    y->right = x;
    x->left = y_right;
    
    x->height = max(get_height(x->left) , get_height(x->right)) + 1;
    x->sum = get_sum(x->left) + get_sum(x->right) + 1;
    y->height = max(get_height(y->left) , get_height(y->right)) + 1;
    y->sum = get_sum(y->left) + get_sum(y->right) + 1;
    return y;
}
node *insert(node *root , int key , int val){

    if(root == NULL)
        return get_new_node(key , val);

    if(key < root->val)
        root->left = insert(root->left , key , val);

    else
        root->right = insert(root->right , key , val);

    root->height = max(get_height(root->left) , get_height(root->right)) + 1;
    root->sum = get_sum(root->left) + get_sum(root->right) + 1;
    int diff ;
    if(root == NULL)
        diff = 0;
    else
        diff = get_height(root->left) - get_height(root->right);

    if(diff > 1 && key < root->left->val)
        return right_rotate(root);
    if(diff < -1 && key > root->right->val)
        return left_rotate(root);
    if(diff > 1 && key > root->left->val){
        root->left = left_rotate(root->left);
        return right_rotate(root);
    }
    if(diff < -1 && key < root->right->val){
        root->right = right_rotate(root->right);
        return left_rotate(root);    
    }
    
    return root;
}
node* get_by_order(node *root , int key){
    if(root == NULL)
        return NULL;
    // cout<<root->val<<" "<<root->num<<endl;
    int left_size = get_sum(root->left);
    if(left_size == key)
        return root;
    if(key < left_size)
        return get_by_order(root->left , key);
    else
        return get_by_order(root->right , key - left_size - 1);
}
int order_of_key(node *root , int key){

    if(root == NULL)
        return 0;

    if(key < root->val)
        return order_of_key(root->left , key);
    else if(key == root->val){
        if(root->left != NULL)
            return get_sum(root->left) + 1;
        else 
            return 1;
    }
    else
    {
        if(root->left != NULL )
            return get_sum(root->left) + 1 + order_of_key(root->right , key);
        else
            return 1 + order_of_key(root->right , key);
    }
}
class data{
public:
    int val , pos , q , t;
    data(){
        val = 0 ;
        pos = 0;
    }
    data(int a ,int b , int c , int d){
        val = a ;
        pos = b ;
        t = c ;
        q = d;
    }
};
bool cmpare(const data &a , const data &b){
    return a.val == b.val ? a.t > b.t : a.val > b.val;
}
int main(){
    int n , q;
    scanf("%d%d",&n,&q);
    node *root = NULL;
    data arr[n+q+9];
    for(int i = 0 ; i < n ; i++){
        int a;
        scanf("%d", &a);
        arr[i] = data(a , i , 1 , 0);
    }
    for(int i = 0 ; i < q ; i++){
        int l , k;
        scanf("%d%d" , &l  ,&k);
        arr[n+i] = data(l , k , 0 , i);
    }
    sort(arr , arr + n+q , cmpare);
    int ans[q+9];
    for(int i = 0 ; i < n+q ; i++){
        if(arr[i].t == 1){
            root = insert(root , arr[i].pos , arr[i].val);
        } else{
            int order = arr[i].pos - 1;
            ans[arr[i].q] =get_by_order(root , order)->num;
        }
    }
    for(int i = 0 ; i < q ; i++)
        printf("%d\n", ans[i]);
    return 0;
}