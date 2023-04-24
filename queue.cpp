#include<iostream>
#include<queue>
using namespace std;

class stack{
    int n;
    queue<int> q1;
    queue<int> q2;
    public:
    stack(){
        n=0;
    }
    void push(int x){
        q1.push(x);
        n++;
    }
    void pop(){
        if(q1.empty()){
            cout<<"queue is empty"<<endl;
            return;
        }
        while(q1.size()!=1){
            q2.push(q1.front());
            q1.pop();
        }
        q1.pop();
        queue<int> temp;

        temp=q2;
        q2=q1;
        q1=temp;
        n--;
    }
    int top(){
        if(q1.empty()){
            cout<<"queue is empty"<<endl;
            return -1;
        }
        while(q1.size()!=1){
            q2.push(q1.front());
            q1.pop();
        }
        int top=q1.front();
        q2.push(q1.front());
        q1.pop();
        queue<int> temp;
        temp=q2;
        q2=q1;
        q1=temp;
        return top;
    }
};
int main(){
    stack st;
    st.push(1);
    st.push(2);
    st.push(3);
    cout<<st.top()<<endl;
    st.pop();
    cout<<st.top()<<endl;
    st.pop();
    cout<<st.top()<<endl;

}