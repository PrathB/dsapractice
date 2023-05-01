#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node* left;
    node* right;

    node(int val){
        data=val;
        left=NULL;
        right=NULL;
    }
};

void inorder(node* root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

node* insertBST(node* root,int val){
    if(root==NULL){
        return new node(val);
    }
    if((root->data)>val){
        root->left=insertBST(root->left,val);
    }
    else{
        root->right=insertBST(root->right,val);
    }
    return root;
}

node* searchBST(node* root, int key){
    if(root==NULL){
        return NULL;
    }
    if(root->data==key){
        return root;
    }
    else if(key<(root->data)){
        return searchBST(root->left,key);
    }
    else if(key>(root->data)){
        return searchBST(root->right,key);
    }
}

int main(){
    node* root=NULL;
    root=insertBST(root,1);
    insertBST(root,3);
    insertBST(root,4);
    insertBST(root,2);
    insertBST(root,7);
    inorder(root);
}