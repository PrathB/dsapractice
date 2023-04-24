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
int Diameter(node* root, int* height){
    if(root==NULL){
        *height=0;
        return 0;
    }
    int lh=0;
    int rh=0;
    int ld=Diameter(root->left,&lh);
    int rd=Diameter(root->right,&rh);
    int currd=lh+rh+1;
    *height=max(lh,rh)+1;
    return max(currd,max(ld,rd));
}
int diameter(node* root){
    if(root==NULL){
        return 0;
    }
    int lheight=treeheight(root->left);
    int rheight=treeheight(root->right);
    int currdiameter=lheight+rheight+1;

    int ldiameter=diameter(root->left);
    int rdiameter=diameter(root->right);
    return(max(currdiameter,max(ldiameter,rdiameter)));
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
bool isbalanced(node* root){
    if(root==NULL){
        return true;
    }
    if(!isbalanced(root->left)){
        return false;
    }
    if(!isbalanced(root->right)){
        return false;
    }
    if(abs(treeheight(root->left)-treeheight(root->right))<=1){
        return true;
    }
    else{
        return false;
    }
}
int main(){
    int Preorder[]={1,2,4,5,3,6,7};
    int Postorder[]={4,5,2,6,7,3,1};
    int Inorder[]={4,2,5,1,6,3,7};
    node* root=Buildtree(Postorder,Inorder,0,6);
    printlevelorder(root);
    cout<<endl;
    cout<<isbalanced(root)<<endl;
}