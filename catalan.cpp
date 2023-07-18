#include<iostream>
#include<vector>
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

int catalan(int n){
    if(n<=1){
        return 1;
    }
    int res=0;
    for(int i=0;i<=n-1;i++){
        res+=catalan(i)*catalan(n-1-i);
    }
    return res;
}

vector<node*> constructTrees(int start, int end){
    vector<node*> trees;
    if(start>end){
        trees.push_back(NULL);
        return trees;
    }
    for(int i=start;i<=end;i++){
        vector<node*> lsubtrees=constructTrees(start,i-1);
        vector<node*> rsubtrees=constructTrees(i+1,end);

        for(int j=0;j<lsubtrees.size();j++){
            node* left=lsubtrees[j];
            for(int k=0;k<rsubtrees.size();k++){
                node* right=rsubtrees[k];
                node* root= new node(i);
                root->left=left;
                root->right=right;
                trees.push_back(root);
            }
        }

    }
    return trees;
} 

void preorder(node* root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}


int main(){
    vector<node*> result=constructTrees(1,3);
    for(int i=0;i<result.size();i++){
        preorder(result[i]);
        cout<<endl;
    }

}