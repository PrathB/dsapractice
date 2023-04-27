#include<iostream>
#include<queue>

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

void preorder(node* root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);

}

void inorder(node* root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

void postorder(node* root){
    if(root==NULL){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}
int search(int inorder[],int curr,int st,int end){
    for(int i=st;i<=end;i++){
        if(curr==inorder[i]){
            return i;
        }
    }
    return -1;
}
node* buildtree(int preorder[],int inorder[],int st,int end){
    if(st>end){
        return NULL;
    }
    static int i=0;
    int curr=preorder[i];
    i++;
    node* n=new node(curr);
    if(st==end){
        return n;
    }
    int pos=search(inorder,curr,st,end);
    n->left=buildtree(preorder,inorder,st,pos-1);
    n->right=buildtree(preorder,inorder,pos+1,end);
}

node* Buildtree(int postorder[],int inorder[],int st,int end){
    if(st>end){
        return NULL;
    }
    static int i=end;
    int curr=postorder[i];
    i--;
    node* n=new node(curr);
    if(st==end){
        return n;
    }
    int pos=search(inorder,curr,st,end);
    n->right=Buildtree(postorder,inorder,pos+1,end);
    n->left=Buildtree(postorder,inorder,st,pos-1);

}

void printlevelorder(node* root){
    queue<node*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        node* n=q.front();
        q.pop();
        if(n!=NULL){
            cout<<n->data<<" ";
            if(n->left!=NULL){
                q.push(n->left);
            }
            if(n->right!=NULL){
                q.push(n->right);
            }
        }
        else if(!q.empty() && n==NULL){
            q.push(NULL);
            cout<<"  ";
        }
    }

}

int sumatk(node* root, int k){
    if(root==NULL){
        return -1;
    }
    queue<node*> q;
    q.push(root);
    q.push(NULL);
    int level=0;
    int sum=0;
    while(!q.empty()){
        node* n=q.front();
        q.pop();
        if(n!=NULL){
            if(level==k){
                sum+=n->data;
            }
            if(n->left!=NULL){
                q.push(n->left);
            }
            if(n->right!=NULL){
                q.push(n->right);
            }
        }
        else if(!q.empty() && n==NULL){
            q.push(NULL);
            level++;
        }
    }
    return sum;
}

int countnodes(node* root){
    if(root==NULL){
        return 0;
    }
    return(countnodes(root->left)+countnodes(root->right)+1);
}
int sumtree(node * root){
    if(root==NULL){
        return 0;
    }
    return(sumtree(root->left)+sumtree(root->right)+(root->data));
}
int treeheight(node* root){
    if(root==NULL){
        return 0;
    }
    int lefth=treeheight(root->left);
    int righth=treeheight(root->right);
    return (max(lefth,righth)+1);
}
int diameter(node* root, int* height){
    if(root==NULL){
        *height=0;
        return 0;
    }
    int lh=0;
    int rh=0;
    int ld=diameter(root->left,&lh);
    int rd=diameter(root->right,&rh);
    int currd=lh+rh+1;
    *height=max(lh,rh)+1;
    return max(currd,max(ld,rd));
}
void sumreplace(node* root){
    if(root == NULL){
        return;
    }
    sumreplace(root->left);
    sumreplace(root->right);

    if(root->left!=NULL){
        root->data+= root->left->data;
    }
    if(root->right!=NULL){
        root->data+= root->right->data;
    }
}

bool isbalanced(node* root, int* height){
    if(root==NULL){
        *height=0;
        return true;
    }
    int lh=0;
    int rh=0;
    if(!isbalanced(root->left,&lh)){
        return false;
    }
    if(!isbalanced(root->right,&rh)){
        return false;
    }
    *height=max(lh,rh)+1;
    if(abs(lh-rh)<=1){
        return true;
    }
    else{
        return false;
    }
}
void rightview(node* root){
    queue<node*> q;
    q.push(root);
    while(!q.empty()){
        int n=q.size();
        for(int i=0;i<n;i++){
            node* curr=q.front();
            q.pop();
            if(i==n-1){
                cout<<curr->data<<" "; 
            }
            if(curr->left!=NULL){
                q.push(curr->left);
            }
            if(curr->right!=NULL){
                q.push(curr->right);
            }
        }
    }
}
void leftview(node* root){
    queue<node*> q;
    q.push(root);
    while(!q.empty()){
        int n=q.size();
        for(int i=0;i<n;i++){
            node* curr=q.front();
            q.pop();
            if(i==0){
                cout<<curr->data<<" ";
            }
            if(curr->left!=NULL){
                q.push(curr->left);
            }
            if(curr->right!=NULL){
                q.push(curr->right);
            }
        }
    }
}
int findDist(node* lca,int k,int d){
    if(lca==NULL){
        return -1;
    }
    if(lca->data==k){
        return d;
    }
    int left=findDist(lca->left,k,d+1);
    if(left!=-1){
        return left;
    }
    int right=findDist(lca->right,k,d+1);
    if(right!=-1){
        return right;
    }
    return -1;
}
node* LCA(node* root, int n1, int n2){
    if(root==NULL){
        return NULL; 
    }
    if(root->data==(n1 || n2)){
        return root;
    }
    node* l=LCA(root->left,n1,n2);
    node* r=LCA(root->right,n1,n2);
    if(l!=NULL && r!=NULL){
        return root;
    }
    if(l==NULL && r==NULL){
        return NULL;
    }
    if(l!=NULL){
        LCA(root->left,n1,n2);
    }
    if(r!=NULL){
        LCA(root->right,n1,n2);
    }
}

int distbwnodes(node* root,int n1,int n2){
    node* lca=LCA(root,n1,n2);
    int d1=findDist(lca,n1,0);
    int d2=findDist(lca,n2,0);
    return (d1+d2);
}

void flatten(node* root){
    if(root==NULL || (root->left==NULL && root->right==NULL)){
        return;
    }
    if(root->left!=NULL){
        flatten(root->left);
        node* temp=root->right;
        root->right=root->left;
        root->left=NULL;
        node* tail=root;
        while(tail->right!=NULL){
            tail=tail->right;
        }
        tail->right=temp;
    }
    flatten(root->right);
}   
void printsubtreenodes(node * target,int k){
    if(target==NULL || k<0){
        return;
    }
    if(k==0){
        cout<<target->data<<" ";
        return;
    }
    printsubtreenodes(target->left,k-1);
    printsubtreenodes(target->right,k-1);
}

int printnodesatk(node* root,node* target,int k){
    if(root==NULL){
        return -1;
    }
    if(root==target){
        printsubtreenodes(root,k);
        return 0;
    }
    int dl=printnodesatk(root->left,target,k);
    if(dl!=-1){
        if(dl+1==k){
            cout<<root->data<<endl;
        }
        else{
            printsubtreenodes(root->right,k-dl-2);
        }
        return dl+1;
    }   
    int dr=printnodesatk(root->right,target,k);
    if(dr=-1){
        if(dr+1==k){
            cout<<root->data<<" ";
        }
        else{
            printsubtreenodes(root->left,k-dr-2);
        }
        return dr+1;
    }
    return -1;
}

int maxpathsum(node* root, int &ans){
    if(root==NULL){
        return 0;
    }
    int lmax=maxpathsum(root->left,ans);
    int rmax=maxpathsum(root->right,ans);
    int currmax=max(max(lmax+(root->data),rmax+(root->data)),max(root->data,lmax+rmax+(root->data)));
    ans=max(ans,currmax);
    return max(max(lmax+(root->data),rmax+(root->data)),root->data);
}

int main(){
    int Preorder[]={1,2,4,5,3,6,7};
    int Postorder[]={4,5,2,6,7,3,1};
    int Inorder[]={4,2,5,1,6,3,7};
    int ans=0;
    node* root=Buildtree(Postorder,Inorder,0,6);
    printlevelorder(root);
    cout<<endl;
    maxpathsum(root,ans);
    cout<<ans<<endl;
}