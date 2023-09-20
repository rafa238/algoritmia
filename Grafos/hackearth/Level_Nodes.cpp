#include <bits/stdc++.h>

using namespace std;
vector<vector<int>> graph;
vector<int> visited;
int targetLevel, targetNodes;

void bfs(){
    queue<pair<int, int>> q;
    q.push({1, 1});
    while(!q.empty()){
        pair<int, int> curr = q.front();
        q.pop();
        if(visited[curr.first]){
            continue;
        }
        visited[curr.first] = true;
        if(curr.second == targetLevel){
            targetNodes++;
        }
        for(auto u : graph[curr.first]){
            q.push({u, curr.second + 1});
        }
    }
}

int main(){
    int n; cin>>n;
    graph.resize(n+1, vector<int>());
    visited.resize(n+1, 0);
    targetNodes = 0;
    for(int i=0; i < n-1; i++){
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    cin >> targetLevel;
    bfs();
    cout << targetNodes << "\n";
    return 0;
}