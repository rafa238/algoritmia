#include<bits/stdc++.h>

using namespace std;
vector<vector<int>> graph;
vector<int> visited;

int n, x;
//1-rides, 2- founded
pair<int, bool> dfs(int u){
    visited[u] = 1;
    int rides = 0;
    bool found = false;
    for(auto v : graph[u]){
        if(visited[v] == 1){
            continue;
        }
        if(v == x){
            return make_pair(1, true);
        }
        pair<int, bool> p = dfs(v);
        
        if(p.second == false){
            rides += p.first + 2;
        } else {
            rides += p.first + 1;
        }
        found = found || p.second;
    }
    return make_pair(rides, found);
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> x;
    graph.assign(n+1,vector<int>());
    visited.assign(n+1, 0);

    for(int i=0; i < n-1; i++){
        int u, v; cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    pair<int, bool> ans = dfs(1);
    cout <<  ans.first << "\n";
    return 0;
}