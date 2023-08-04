#include<iostream>
using namespace std;

class trienode{
    public:
    char data;
    trienode* children[26];
    bool isterminal;
    
    trienode(char val){
        data=val;
        for(int i=0;i<26;i++){
            children[i]=NULL;
        }
        isterminal=false;
    }
};

class trie{
    public:
    trienode* root;

    trie(){
        root=new trienode('\0');
    }
    
    //Functions are created to work for string with capital letters only
    
    void insertword(trienode* root,string word){
        if(word.size()==0){
            root->isterminal=true;
            return;
        }

        int index=word[0]-'A';
        if(root->children[index]==NULL){
            root->children[index]=new trienode(word[0]);
        }
        else{
            root->children[index]->data=word[0];
        }

        insertword(root->children[index],word.substr(1));
    }

    bool searchword(trienode* root,string word){
        if(word.size()==0){
            return root->isterminal;
        }

        int index=word[0]-'A';
        trienode* child;
        if(root->children[index]!=NULL){
            child=root->children[index];
        }
        else{
            return false;
        }

        return searchword(child,word.substr(1));
    }
};
int main(){
    trie* t=new trie();
    t->insertword(t->root,"HELLO");
    cout<<t->searchword(t->root,"HELL");
    return 0;
}