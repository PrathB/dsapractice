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
node* inordersucc(node* root){
    node* curr=root;
    while(curr && curr->left!=NULL){
        curr=curr->left;
    }
    return curr;
}
node* deleteInBST(node* root,int key){
    if((root->data)>key){
        root->left=deleteInBST(root->left,key);
    }
    else if((root->data)<key){
        root->right=deleteInBST(root->right,key);
    }
    else if((root->data)==key){
        if(root->left==NULL){
            node* temp=root->right;
            free(root);
            return temp;
        }
        else if(root->right==NULL){
            node* temp=root->left;
            free(root);
            return temp;
        }
        else if(root->left!=NULL && root->right!=NULL){
            node* temp=inordersucc(root->right);
            root->data=temp->data;
            root->right=deleteInBST(root->right,temp->data);
        }
    }
    return root;
}
int main(){
    node* root=NULL;
    root=insertBST(root,1);
    insertBST(root,3);
    insertBST(root,4);
    insertBST(root,2);
    insertBST(root,7);
    root=deleteInBST(root,3);
    inorder(root);
}