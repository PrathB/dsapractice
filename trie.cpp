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

int main(){
    trienode* root=new trienode('\0');
    insertword(root,"HELLO");
    return 0;
}