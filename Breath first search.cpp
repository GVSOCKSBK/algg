#include<bits/stdc++.h>
using namespace std;

// Breath First Search (BFS)     

const int N = 1e5+2;

int main(){
    int n,m;
    cin>>n>>m;
    bool vis[N];     // visited array
    vector<int> adj[n+1];  // adjacency list  

    int x, y;
    for(int i=0; i<m; i++){
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    for(int i=0; i<N; i++){
        vis[i] = 0;
    }

    queue<int> q;
    q.push(1);
    vis[1] = true;

    while(!q.empty()){
        int node = q.front();
        q.pop();
        cout<<node<<endl;

        for(auto it : adj[node]){
            if(vis[it]==false){
                q.push(it);
                vis[it] = 1;
            }
        }
    }

    return 0;
}