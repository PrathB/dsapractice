#include<iostream>
#include<stack>
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

node* sortedarraytoBST(int arr[],int s,int e){
    if(s>e){
        return NULL;
    }
    int mid=(s+e)/2;
    node* root=new node(arr[mid]);
    root->left=sortedarraytoBST(arr,s,mid-1);
    root->right=sortedarraytoBST(arr,mid+1,e);
    return root;
}

void zigzagtraversal(node* root){
    stack<node*> currlvl;
    stack<node*> nextlvl;
    bool lefttoright=true;
    currlvl.push(root);
    while(!currlvl.empty()){
        cout<<currlvl.top()->data<<" ";
        if(lefttoright){
            if(currlvl.top()->left!=NULL){
                nextlvl.push(currlvl.top()->left);}
            if(currlvl.top()->right!=NULL){
                nextlvl.push(currlvl.top()->right);}
        }
        else{
            if(currlvl.top()->right!=NULL)    
                nextlvl.push(currlvl.top()->right);
            if(currlvl.top()->left!=NULL){
                nextlvl.push(currlvl.top()->left);}
        }
        currlvl.pop();
        if(currlvl.empty()){
            lefttoright=!lefttoright;
            stack<node*> temp=nextlvl;
            nextlvl=currlvl;
            currlvl=temp;
        }
    } 
}

bool isidentical(node* root1,node* root2){
    if(root1==NULL && root2==NULL){
        return true;
    }
    else if(root1==NULL || root2==NULL){
        return false;
    }
    else{
        if(root1->data==root2->data && isidentical(root1->left,root2->left) && isidentical(root1->right,root2->right)){
            return true;
        }
        else{
            return false;
        }
    }
}

int main(){
    node* root1=new node(12);
    root1->left=new node(9);
    root1->right=new node(15);
    root1->left->left=new node(5);
    root1->left->right=new node(10);

    node* root2=new node(12);
    root2->left=new node(9);
    root2->right=new node(15);
    root2->left->left=new node(5);
    root2->left->right=new node(10);
    cout<<isidentical(root1,root2);
}