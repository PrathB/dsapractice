#include<iostream>
#include<stack>
#include<vector>
#include<utility>
#include<algorithm>

using namespace std;
int main(){
    string s="pwwkew";
    vector<int> d(256,-1);
    int ans=0;
    int st=-1;
    for(int i=0;i<s.length();i++){
        if(d[s[i]]>st){
            st=d[s[i]];
        }
        d[s[i]]=i;
        ans=max(ans,i-st);
    }
    
    cout<<ans<<endl;
}


