#include<iostream>
#include<deque>
#include<vector>
using namespace std;
int main(){
    int arr[]={3,5,8,4,8,9,1};
    int n=7;
    deque<int> d;
    int k=4;
    vector<int> ans;
    for(int i=0;i<k;i++){
        while(!d.empty() && arr[d.back()]<arr[i]){
            d.pop_back();
        }
        d.push_back(i);
    }
    ans.push_back(arr[d.front()]);

    for(int i=k;i<n;i++){
        if(d.front()==i-k){
            d.pop_front();
        }
        else{
            while(!d.empty() && arr[d.back()]<arr[i]){
                d.pop_back();
            }
            d.push_back(i);
        }
        ans.push_back(arr[d.front()]);
    }

    for(auto i: ans){
        cout<<i<<" ";
    }
}