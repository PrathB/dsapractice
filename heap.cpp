#include<iostream>
using namespace std;

class heap{
    public:
    int arr[100];
    int size;

    heap(){
        size=0;
        arr[0]=-1;
    }

    void insert(int val){
        size++;
        int index=size;
        arr[size]=val;

        while(index>1){
            int parent=index/2;
            if(arr[parent]<arr[index]){
                swap(arr[parent],arr[index]);
                index=parent;
            }
            else{
                return;
            }
        }
    }

    void deleteroot(){
        arr[1]=arr[size];
        size--;
        int i=1;
        while(i<size){
            int lchild=2*i;
            int rchild=2*i+1;
            if(lchild<=size && arr[i]<arr[lchild] && arr[lchild]>arr[rchild]){
                swap(arr[lchild],arr[i]);
                i=lchild;
            }
            else if(rchild<=size && arr[i]<arr[rchild] && arr[rchild]>arr[lchild]){
                swap(arr[rchild],arr[i]);
                i=rchild;
            }
            else{
                return;
            }
        }
    }

    void print(){
        for(int i=1;i<=size;i++){
            cout<<arr[i]<<" ";
        }
    }

};

void heapify(int arr[],int n,int i){
    int largest=i;
    int lchild=2*i;
    int rchild=(2*i)+1;

    if(lchild<=n && arr[largest]<arr[lchild]){
        largest=lchild;
    }
    if(rchild<=n && arr[largest]<arr[rchild]){
        largest=rchild;
    }

    if(largest!=i){
        swap(arr[largest],arr[i]);
        heapify(arr,n,largest);
    }
    return;
}

void heapsort(int arr[],int n){
    int size=n;
    while(size>1){
        swap(arr[1],arr[size]);
        size--;

        heapify(arr,size,1);
    }
    return;
}
int main(){
    heap h;
    h.insert(50);
    h.insert(55);
    h.insert(53);
    h.insert(52);
    h.insert(54);
    h.print();
    cout<<endl;
    h.deleteroot();
    h.print();
    cout<<endl;

    int arr[]={-1,54,53,55,52,50};
    int n=5;

    //heapcreation
    for(int i=n/2;i>=1;i--){
       heapify(arr,n,i); 
    }
    cout<<"heapified array: ";
    for(int i=1;i<=n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    //heapsort
    heapsort(arr,n);

    cout<<"sorted array: ";
    for(int i=1;i<=n;i++){
        cout<<arr[i]<<" ";
    }

}