#include<iostream>
#include<stack>
#include<math.h>
#include<string>
using namespace std;
void InsertAtBottom(stack<int> &st,int el){
    if(st.empty()==1){
        st.push(el);
        return;
    }
    int e=st.top();
    st.pop();
    InsertAtBottom(st,el);
    st.push(e);

}
void ReverseStack(stack<int> &st){
    if(st.empty()==1){
        return;
    }
    int el=st.top();
    st.pop();
    ReverseStack(st);
    InsertAtBottom(st,el);
}

int PrefixEvaluation(string s){
    stack<int> st;
    for(int i=s.length()-1;i>=0;i--){
        if(s[i]>='0' && s[i]<='9'){
            st.push(s[i]-'0');
        }
        else{
            int op1=st.top();
            st.pop();
            int op2=st.top();
            st.pop();

            switch (s[i])
            {
            case '+':
                st.push(op1+op2);
                break;
            case '-':
                st.push(op1-op2);
                break;
            case '*':
                st.push(op1*op2);
                break;
            case '/':
                st.push(op1/op2);
                break;
            case '^':
                st.push(pow(op1,op2));
                break;
            }

        }
    }
    return st.top();
}

int PostfixEvaluation(string s){
    stack<int> st;
    for(int i=0;i<=s.length()-1;i++){
        if(s[i]>='0' && s[i]<='9'){
            st.push(s[i]-'0');
        }
        else{
            int op2=st.top();
            st.pop();
            int op1=st.top();
            st.pop();

            switch (s[i])
            {
            case '+':
                st.push(op1+op2);
                break;
            case '-':
                st.push(op1-op2);
                break;
            case '*':
                st.push(op1*op2);
                break;
            case '/':
                st.push(op1/op2);
                break;
            case '^':
                st.push(pow(op1,op2));
                break;
            default:
                break;
            }
        }
    }
    return st.top();
}
int oppre(char op){
    if(op=='('){
        return 3;
    }
    else if(op=='*' || op=='/'){
        return 2;
    }
    else if (op=='+' || op=='-'){
        return 1;
    }
    else{
        return -1;
    }
}

string InfixToPostfix(string s){
    string res="";
    stack<char> st;
    for(int i=0;i<(s.length());i++){
        if(s[i]>='0' && s[i]<='9'){
            res+=s[i];
        }
        else if(s[i]=='('){
            st.push(s[i]);
        }
        else if(s[i]==')'){
            while(st.empty()==0 && st.top()!='('){
                res+=st.top();
                st.pop();
            }
            if(st.empty()==0){
                st.pop();
            }
        }
        else{
            if(oppre(s[i])>=oppre(st.top())){
                st.push(s[i]);
            }
            else{
                while(st.empty()==0 && oppre(s[i])<oppre(st.top())){
                    if(st.top()=='('){
                        st.pop();
                    }
                    else{
                        res+=st.top();
                        st.pop();
                    }
                }
                if(st.empty()==0){
                    st.push(s[i]);
                }
            }
        }
    }
    while(st.empty()==0){
        res+=st.top();
        st.pop();
    }
    return res;
}

bool IsBalanced(string s){
    stack<char> st;
    bool ans=1;
    for(int i=0;i<=s.length()-1;i++){
        if(s[i]=='(' || s[i]=='{' || s[i]=='['){
            st.push(s[i]);
        }
        else if(s[i]==')'){
            if(st.empty()==0 && st.top()=='('){
                st.pop();
            }
            else{
                ans=0;
                break;
            }
            
        }
        else if(s[i]=='}'){
            if(st.empty()==0 && st.top()=='{'){
                st.pop();
            }
            else{
                ans=0;
                break;
            }
        }
        else if(s[i]==']'){
            if(st.empty()==0 && st.top()=='['){
                st.pop();
            }
            else{
                ans=0;
                break;
            }
        }
        else{
            ans=0;
            break;
        }
    }
    if(st.empty()==1 && ans==1){
        return 1;
    }
    else{
        return 0;
    }
}


int main(){   
    cout<<IsBalanced("({}){");
}
