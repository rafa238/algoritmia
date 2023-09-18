#include<bits/stdc++.h>

using namespace std;
vector<vector<int>> graph;
vector<int> visited, colors;
int n, m;

bool isBipartite(int u){
    visited[u] = 1;
    for(auto v : graph[u]){
        if(colors[u] == colors[v]) return false;
        else if(!visited[v]){
            colors[v] = !colors[u];
            if(!isBipartite(v)) return false;
        }
    }
    return true;
}

int main(){
    cin>>n>>m;
    graph.resize(n+1, vector<int>());
    visited.resize(n+1, 0);
    colors.resize(n+1, -1);
    for(int i=0; i<m; i++){
        int u, v;
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    bool bipartite = true;
    for(int i=0; i<=n; i++){
        if(visited[i] == 0){
            colors[i] = 0;
            bipartite = bipartite && isBipartite(i);
        }
    }
    if(bipartite){
        for(int i=1; i<=n; i++){
            cout << colors[i] + 1<<" ";
        }
    } else {
        cout<<"IMPOSSIBLE";
    }
    return 0;
}