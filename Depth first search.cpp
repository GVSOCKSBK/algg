#include<bits/stdc++.h>
using namespace std;

// Depth First Search (DFS)

const int N = 1e5+2;

void dfs(int node, bool vis[], vector<int> adj[]){
    // preorder     
    vis[node] = 1;
    cout<<node<<endl;

    // inorder
    for(auto it : adj[node]){
        if(vis[it]==false){
            dfs(it,vis,adj);
        }
    }

}

int main(){
    int n,m;
    cin>>n>>m;
    bool vis[N];
    vector<int> adj[n+1];    // array of vectors

    for(int i=0; i<N; i++){
        vis[i] = 0;
    }

    int x,y;
    for(int i=0; i<m; i++){
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    for(int i=1; i<n+1; i++){
        if(vis[i]==false){
            dfs(i,vis,adj);
        }
    }
    
    return 0;
}