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

node* constructBST(int preorder[],int* preorderidx,int key,int min,int max,int n){
    if(*preorderidx>n){
        return NULL;
    }
    node* root=NULL;
    if(key>min && key<max){
        root=new node(key);
        *preorderidx+=1;

        if(*preorderidx<n){
            root->left=constructBST(preorder,preorderidx,preorder[*preorderidx],min,key,n);
        }
        if(*preorderidx<n){
            root->right=constructBST(preorder,preorderidx,preorder[*preorderidx],key,max,n);
        }
    }
    
    return root;
}

bool isBST(node* root,node * min=NULL, node* max=NULL){
    if(root==NULL){
        return true;
    }
    if(min!=NULL && root->data<=min->data){
        return false;
    }
    if(max!=NULL && root->data>=max->data){
        return false;
    }
    bool lvalid=isBST(root->left,min,root);
    bool rvalid=isBST(root->right,root,max);
    return lvalid && rvalid;
}
int main(){
    node* root1=new node(2);
    root1->left=new node(1);
    root1->right=new node(3);
    cout<<isBST(root1);

}