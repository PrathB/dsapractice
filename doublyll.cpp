#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node* next=NULL;
    node* prev=NULL;
};
void InsertatHead(node* &head,int val){
    node* n=new node;
    n->data=val;
    if(head==NULL){
        head=n;
        return;
    }
    head->prev=n;
    n->next=head;
    head=n;
    return;
}

void InsertatTail(node* &head,int val){
    if(head==NULL){
        InsertatHead(head,val);
        return;
    }
    node* temp=head;
    node* n=new node;
    n->data=val;
    while(temp->next!=NULL){
        temp=temp->next;
    }   
    temp->next=n;
    n->prev=temp;
    return;
}

void Display(node* head){
    node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

void DeleteatHead(node* &head){
    if(head==NULL){
        return;
    }
    if(head->next==NULL){
        node* temp=head;
        head=NULL;
        delete temp;
        return;
    }
    else{
        head->next->prev=NULL;
        node* temp=head;
        head=head->next;
        delete temp;
        return;
    }
}

void Deletion(node* &head,int pos){
    if(pos==1){
        DeleteatHead(head);
        return;
    }
    node* temp=head;
    int count=1;
    while(temp!=NULL && count!=pos){
        temp=temp->next;
        count++;
    }
    if(temp->next==NULL){
        temp->prev->next=NULL;
        delete temp;
        return;
    }
    else{
        temp->prev->next=temp->next;
        temp->next->prev=temp->prev;
        delete temp;
        return;
    }
}
int main(){
    node* head=NULL;
    InsertatTail(head,2);
    InsertatTail(head,3);
    InsertatHead(head,1);
    InsertatTail(head,4);
    Display(head);
    Deletion(head,4);
    Display(head);
}