#include<iostream>
#include<climits>
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

struct info{
    int size;
    int min;
    int max;
    int ans;
    bool isBST;

};

info largestBSTinBT(node* root){
    if(root==NULL){
        return {0,INT_MAX,INT_MIN,0,true};
    }
    if(root->left==NULL && root->right==NULL){
        return {1,root->data,root->data,1,true};
    }

    info curr;
    info left=largestBSTinBT(root->left);
    info right=largestBSTinBT(root->right);
    curr.size=(1+left.size+right.size);
    curr.min=min(min(left.min,right.min),root->data);
    curr.max-max(max(left.max,right.max),root->data);
    if(left.isBST==true && right.isBST==true && root->data>left.max && root->data<right.min){
        curr.ans=curr.size;
        curr.isBST=true;
        return curr;
    }
    curr.ans=max(left.ans,right.ans);
    curr.isBST=false;
    return curr;
}

int main(){
    /*

    10
   /  \
  5   11
  /
 2 

    */
    node* root1=new node(10);
    root1->left=new node(5);
    root1->right=new node(11);
    root1->left->left=new node(2);
    cout<<largestBSTinBT(root1).ans;
}