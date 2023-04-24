#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node *next;

    node(int val){
        data=val;
        next=NULL;
    }

    node(){
    }
};

void AddtoHead(node* &head,int val){
    node* temp=head;
    node * n=new node(val);
    if(head==NULL){
        head=n;
        n->next=n;
        return;
    }
    while(temp->next!=head){
        temp=temp->next;
    }
    temp->next=n;
    n->next=head;
    head=n;
    return;
}
void AddtoTail(node* &head,int val){
    if(head==NULL){
        AddtoHead(head,val);
        return;
    }
    node* temp=head;
    node* n=new node(val);
    while(temp->next!=head){
        temp=temp->next;
    }
    temp->next=n;
    n->next=head;
    return;
}

void Display(node* head){
    node* temp=head;
    while(temp->next!=head){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<(temp->data)<<endl;
}
void DeleteatHead(node* &head){
    node* temp=head;
    while(temp->next!=head){
        temp=temp->next;
    }
    node* del=head;
    head=head->next;
    temp->next=head;
    delete del;
    return;
}
void Deletion(node* &head,int pos){
    if(pos==1){
        DeleteatHead(head);
        return;
    }
    node*temp=head;
    while(pos!=2){
        temp=temp->next;
        pos--;
    }
    node* del=temp->next;
    temp->next=temp->next->next;
    delete del;
    return;
}

int main(){
    node* head=NULL;
    AddtoTail(head,1);
    AddtoTail(head,2);
    AddtoTail(head,3);
    AddtoTail(head,4);
    Display(head);
    Deletion(head,5);
    Display(head);

}