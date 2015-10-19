/*
===================================================
Name :- Nishant Raj
Email :- raj.nishant360@gmail.com
College :- Indian School of Mines
Branch :- Computer Science and Engineering
Time :- 03 October 2015 (Saturday) 14:44
===================================================*/
#include <bits/stdc++.h>
using namespace std;
class node{
public:
    int val , height,pointer ;
    vector<int> pos;
    node * left , *right;
    node(){
        val = height = pointer = 0;
        left = right = NULL;    
    }
};
node *get_new_node(int key , int p){

    node *temp = new node();
    temp->val =  key;
    temp->left = NULL;
    temp->right = NULL;
    temp->height = 1;
    temp->pos.push_back(p);
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
    y->height = max(get_height(y->left) , get_height(y->right)) + 1;
    return y;
}

node *right_rotate(node *x){

    node *y = x->left;
    node *y_right = y->right;

    y->right = x;
    x->left = y_right;
    
    x->height = max(get_height(x->left) , get_height(x->right)) + 1;
    y->height = max(get_height(y->left) , get_height(y->right)) + 1;
    return y;
}
node *insert(node *root , int key , int p){

    if(root == NULL)
        return get_new_node(key , p);

    if(key < root->val)
        root->left = insert(root->left , key , p);
    else if(key > root->val)
        root->right = insert(root->right , key , p);
    else{
        root->pos.push_back(p);
        return root;
    }
    root->height = max(get_height(root->left) , get_height(root->right)) + 1;
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
node *find_ans(node *root , int val){
    if(root == NULL)
        return NULL;
    if(root->val < val)
        return find_ans(root->right , val);
    else if(root->val > val)
        return find_ans(root->left , val);
    else
        return root;
}
#define gc getchar_unlocked
void scanint(int &x)
{
    register int c = gc();
    x = 0;
    int neg = 0;
    for(;((c<48 || c>57) && c != '-');c = gc());
    if(c=='-') {neg=1;c=gc();}
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
    if(neg) x=-x;
}
void scanchar(char &c){
    register int x = gc();
    for(;(x < 65 || x > 97);x = gc());
    c = x;
}
int main(){
    
    int n , m , temp;
    scanint(n);
    scanint(m);
    node *root = NULL;
    for(int i = 1 ; i<= n ; i++){
        scanint(temp);
        root = insert(root , temp , i);
    }
    int initial_size = n;
    while(m--){

        char c ;
        int value;
        scanchar(c);
        scanint(value);
        if(c == 'S'){
            node *temp = find_ans(root , value);
            if(temp == NULL){
                printf("NONE\n");
            } else{
                printf("%d\n" , temp->pos[temp->pointer]);
            }
        } else if(c == 'I'){
            initial_size++;
            root = insert(root , value , initial_size);
            printf("%d\n" , initial_size);
        } else{
            node *temp = find_ans(root , value);
            if(temp == NULL){
                printf("NONE\n");
            } else{
                printf("%d\n", temp->pos[temp->pointer]);
                if(temp->pointer < temp->pos.size()-1)
                    temp->pointer++;
                else
                    root = del(root , value);
            }
        }
    }
    return 0;
}