#include<iostream>
#include<unordered_map>
#include<vector>
#include<queue>
using namespace std;

class graph{
    public:

    unordered_map<int,vector<int>> adj;

    void addedge(int u,int v,bool directional){
        adj[u].push_back(v);
        //directional=1 for directed graph
        //directional=0 fot undirected graph
        if(!directional){
            adj[v].push_back(u);
        }
    }

    void printadjlist(){
        for(auto i:adj){
            cout<< i.first<<"->";
            for(auto j: i.second){
                cout<<j<<",";
            }
            cout<<endl;
        }
    }
};

//fxn to prepare adj list from given graph edges 
void preparedAdjList(vector<vector<int>> &adjList, vector<pair<int, int>> &edges){
    for(int i=0; i<edges.size();i++){
        int u= edges[i].first;
        int v= edges[i].second;
        
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
}

vector<int> bfsTraversal(int n, vector<vector<int>> &adj){
    //creating visisted map to mark already traversed nodes
    unordered_map<int,bool> visited;
    for(int i=0;i<n;i++){
        visited[i]=0;
    }

    vector<int> ans;

    queue<int> q;

    q.push(0);
    visited[0]=1;
    int frontnode;
    while(!q.empty()){
        //adding the front node to ans vector
        frontnode=q.front();
        ans.push_back(frontnode);
        q.pop();

        //pushing connected nodes to frontnode from adj list
        for(int i=0;i<adj[frontnode].size();i++){
            if (visited[adj[frontnode][i]] == 0) {
                q.push(adj[frontnode][i]);
                visited[adj[frontnode][i]]=1;
            }
        }
    }
    
    return ans;

}

int main(){
    int n;
    cout<<"Enter no. of nodes"<<endl;
    cin>>n;

    int m;
    cout<<"Enter no. of edges"<<endl;
    cin>>m;

    graph g;
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        g.addedge(u,v,0);
    }

    g.printadjlist();
}
