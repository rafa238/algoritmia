#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> graph;
vector<bool> visited;
int n, m;
void dfs(int u){
    if(visited[u])
        return;
    visited[u] = true;
    for(auto v : graph[u]){
        dfs(v);
    }
}

int main(){
    cin>>n>>m;
    graph.resize(n+1, vector<int>());
    visited.resize(n+1, false);
    for(int i=0; i<m; i++){
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    int countComponents = 0;
    vector<int> rootComponents;
    for(int i=1; i<=n; i++){
        if(!visited[i]){
            countComponents++;
            rootComponents.push_back(i);
            dfs(i);
        }
    }
    cout << countComponents - 1 << "\n";
    if(countComponents - 1 != 0){
        for(int i=1; i< countComponents; i++){
            cout << rootComponents[i-1]  << " " << rootComponents[i] << "\n";
        }
    }
    return 0;
}