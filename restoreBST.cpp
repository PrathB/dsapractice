#include<iostream>
using namespace std;

struct node{
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

void swap(node** a,node** b){
    int temp=(*a)->data;
    (*a)->data=(*b)->data;
    (*b)->data=temp;
}

void calcpointers(node* root,node** first,node** mid,node** last,node** prev){
    if(root==NULL){
        return;
    }

    calcpointers(root->left,first,mid,last,prev);

    if(*prev!=NULL && root->data<(*prev)->data){
        if(*first==NULL){
            *first=*prev;
            *mid=root;
        }
        else{
            *last=root;
        }
    }
    *prev=root;

    calcpointers(root->right,first,mid,last,prev);
}
void restoreBST(node* root){
    node* first=NULL;
    node* mid=NULL;
    node* last=NULL;
    node* prev=NULL;

    calcpointers(root,&first,&mid,&last,&prev);

    if(first!=NULL && last!=NULL){
        swap(&first,&last);
    }

    else if (first!=NULL && mid!=NULL){
        swap(&first,&mid);
    }
    return;
}

int main(){
    node* root=new node(6);
    root->left=new node(9);
    root->right=new node(3);
    root->left->left=new node(1);
    root->left->right=new node(4);
    root->right->right=new node(13);
    inorder(root);
    cout<<endl;
    restoreBST(root);
    inorder(root);
}