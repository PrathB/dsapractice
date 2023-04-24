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

int Length(node* head){
    node* temp=head;
    int count=0;
    while(temp!=NULL){
        temp=temp->next;
        count++;
    }
    return count; 
}

void AddtoHead(node* &head,int val){
      node *n=new node(val);
      n->next=head;
      head=n;  
    }

void AddtoTail(node* &head,int val){
    node *n=new node(val);
    if(head==NULL){
        AddtoHead(head,val);
    }
    else{
        node *temp=head;
        while((temp->next)!=NULL){
            temp=temp->next;
        }
        temp->next=n;
    }
}

void Display(node* head){
    node *temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

bool Search(node* head,int key){
    node *temp=head;
    while(temp!=NULL){
        if((temp->data)==key){
            return true;
        }
        temp=temp->next;
    }
    return false;
}

void DeleteatHead(node* &head){
    node *todel=head;
    head=head->next;
    delete todel;
}
void Deletion(node* &head,int val){
    if(head==NULL){
        return;
    }
    if(head->next==NULL){
        DeleteatHead(head);
        return;
    }
    if(head->data==val){
        DeleteatHead(head);
        return;
    }
    node *temp=head;
    while(temp->next->data!=val){
        temp=temp->next;
    }
    node *todel=temp->next;
    (temp->next)=(temp->next->next);
    delete todel;
}

node* Reverse(node* &head){
    node* prev=NULL;
    node* curr=head;
    node* next;
    while(curr!=NULL){
        next=curr->next;
        curr->next=prev;

        prev=curr;
        curr=next;
    }
    return prev;
}

node* ReverseRecursive(node* &head){
    if(head->next==NULL||head==NULL){
        return head;
    }
    
    node *newhead=ReverseRecursive(head->next);
    head->next->next=head;
    head->next=NULL;

    return newhead;
}

node* Reversek(node* &head,int k){
    int count=0;
    node *prev=NULL;
    node* curr=head;
    node* next;
    while(curr!=NULL && count<=k-1){
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
        count++;
    }
    if(curr!=NULL){
    head->next=Reversek(curr,k);
    }

    return prev;
}
void MakeCycle(node* &head,int pos){
    node *start;
    node *temp=head;
    int count=1;
    while(temp->next!=NULL){
        if(count==pos){
            start=temp;
        }
        temp=temp->next;
        count++;
    }
    temp->next=start;
}

bool DetectCycle(node* head){
    node* slow=head;
    node* fast=head;
    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast){
            return 1;
        }
    }
    return 0;
}  

void RemoveCycle(node* &head){
    node* slow=head;
    node* fast=head;
    do{
        slow=slow->next;
        fast=fast->next->next;
    }while(slow!=fast);

    if(fast==head){
        while(fast->next!=NULL){
            fast=fast->next;
        }
        fast->next=NULL;
    }
    else{
    
        fast=head;
    
        while(fast->next!=slow->next){
            fast=fast->next;
            slow=slow->next;
        }
        slow->next=NULL;
    }
}   

void AppendLastk(node* &head,int k){
    node* newhead;
    node* newtail;
    node* tail=head;;
    int count=1;
    int l=Length(head);
    while(tail->next!=NULL){
        if(count==(l-k)){
            newtail=tail;
        }
        if(count==(l-k+1)){
            newhead=tail;
        }
        tail=tail->next;
        count++;
    }
    newtail->next=NULL;
    tail->next=head;
    head=newhead;
    return;
}   

int intersection(node* head1,node* head2){
    node* ptr1;
    node* ptr2;
    int l1=Length(head1);
    int l2=Length(head2);
    int diff;
    if(l2==l1){
        diff=0;
        ptr1=head1;
        ptr2=head2;
    }
    else if(l1>l2){
        diff=l1-l2;
        ptr1=head1;
        ptr2=head2;
    }
    else{
        diff=l2-l1;
        ptr1=head2;
        ptr2=head1;
    }
    while(diff!=0){
        ptr1=ptr1->next;
        diff--;
        if(ptr1==NULL){
            return -1;
        }
    }
    while(ptr1!=NULL && ptr2!=NULL){
        if(ptr1==ptr2){
            return ptr1->data;
        }
        ptr1=ptr1->next;
        ptr2=ptr2->next;
    }
    return -1;
}

node* merge(node* &head1,node* &head2){
    node *dummy=new node(-1);
    node* ptr1=head1;
    node* ptr2=head2;
    node* ptr3=dummy;
    while(ptr1!=NULL && ptr2!=NULL){
        if((ptr1->data)<(ptr2->data) && ptr1!=NULL && ptr2!=NULL){
            ptr3->next=ptr1;
            ptr1=ptr1->next;
            ptr3=ptr3->next;    
        }
        else if((ptr1->data)>(ptr2->data) && ptr1!=NULL && ptr2!=NULL){
            ptr3->next=ptr2;
            ptr2=ptr2->next;
            ptr3=ptr3->next;
        }
        else if(ptr1==NULL && ptr2!=NULL){
            ptr3->next=ptr2;
        }
        else if(ptr1!=NULL && ptr2==NULL){
            ptr3->next=ptr1;
        }
    }
    ptr3->next=NULL;
    return dummy->next;

}

node* mergerecursive(node* &head1,node* &head2){
    if(head1==NULL){
        return head2;
    }
    if(head2==NULL){
        return head1;
    }
    node* result;
    if(head1->data>head2->data){
        result=head2;
        result->next=mergerecursive(head1,head2->next);
    }
    else{
        result=head1;
        result->next=mergerecursive(head1->next,head2);
    }
    return result;
}

void evenafterodd(node* &head){
    node* odd=head;
    node* even=head->next;
    node* evenstart=even;
    while(odd->next!=NULL && even->next!=NULL){
        if(even->next!=NULL){
            odd->next=even->next;
            odd=odd->next;
        }
        if(odd->next!=NULL){
            even->next=odd->next;
            even=even->next;
        }
    }
    odd->next=evenstart;
    even->next=NULL;
    return;
}
int main(){
    node *head1=NULL,*head2=NULL;
    AddtoTail(head1,1);
    AddtoTail(head1,2);
    AddtoTail(head1,3);
    AddtoTail(head1,4);
    Display(head1);
    evenafterodd(head1);
    Display(head1);
}