#include <bits/stdc++.h>
using namespace std;
class node{
public:
    int val , height , sum ;
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
node *get_new_node(int key){

    node *temp = new node();
    temp->val =     key;
    temp->left = NULL;
    temp->right = NULL;
    temp->height = 1;
    temp->sum = 1;
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
node *insert(node *root , int key){

    if(root == NULL)
        return get_new_node(key);

    if(key < root->val)
        root->left = insert(root->left , key);

    else
        root->right = insert(root->right , key);

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
node *del(node * root , int key){

    if(root == NULL)
        return root;
    
    if(key < root->val)
        root->left = del(root->left , key);
    else if(key > root->val)
        root->right = del(root->right , key);

    else{
        
        if(root->left == NULL || root->right == NULL){
            
            node *temp = root->left ? root->left : root->right;
            if(temp == NULL){
                
                temp = root;
                root = NULL;
            }
            else
                *root = *temp;        
        }
        else{
            
            node *temp = root->right;
            while(temp->left != NULL)
                temp = temp->left;
            
            root->val = temp->val;

            root->right = del(root->right , temp->val);        
        }
    }
    
    if(root == NULL)
        return root;
    root->height = max(get_height(root->left) , get_height(root->right)) + 1;
    root->sum = get_sum(root->left) + get_sum(root->right) + 1;
    int diff = get_height(root->left) - get_height(root->right);
    
    if (diff > 1 && get_diff(root->left) >= 0)
        return right_rotate(root);
 
    if (diff > 1 && get_diff(root->left) < 0)
    {
        root->left =  left_rotate(root->left);
        return right_rotate(root);
    }
 
    if (diff < -1 && get_diff(root->right) <= 0)
        return left_rotate(root);
 
    if (diff < -1 && get_diff(root->right) > 0)
    {
        root->right = right_rotate(root->right);
        return left_rotate(root);
    }
    return root;
}
int get_by_order(node *root , int key){

    if(root == NULL)
        return 0;
    int left_size = get_sum(root->left);
    if(left_size == key)
        return root->val;
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

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        node *root = NULL;
        int count = 0;
        while(true){
            int value;
            scanf("%d", &value);
            if(value == 0)
                break;
            if(value!= -1){
                root = insert(root , value);
                count++;
            }
            else{
                int ans=0;
                if(count&1)
                    ans = get_by_order(root , (count>>1));
                else
                    ans = get_by_order(root , (count>>1)-1);
                printf("%d\n",ans);
                root = del(root , ans) ;
                count--;
            }
        }
    }
    return 0;
}
