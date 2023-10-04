#include <bits/stdc++.h>

using namespace std;
vector<vector<int>> graph;
vector<bool> visited;
vector<int> leafsA;

//is leaf and isOk
pair<bool, bool> dfs(int u){
    if(visited[u]) return {true, true};
    visited[u] = true;
    if(graph[u].size() == 0){
        return {true, true};
    }
    int leafs = 0;
    bool isOk = true;
    for(auto v : graph[u]){
        pair<bool, bool> isLeaf = dfs(v);
        isOk = isOk && isLeaf.second;
        if(isLeaf.first){
            leafs++;
        }
    }
    bool imOk = (leafs >= 3);
    return {false,  imOk && isOk};
}

int main(){
    int n;
    cin >> n;
    graph.resize(n+1, vector<int>());
    visited.resize(n+1, false);
    leafsA.assign(n+1, 0);
    for(int i=2; i<= n; i++){
        int u; cin >> u;
        graph[u].push_back(i);
    }
    bool ans = dfs(1).second;
    
    
    /*for(int i=1; i<=n; i++){
        //cout << leafsA[i] << " ";
        if(leafsA[i] == 0){
            continue;
        } else if(leafsA[i] < 3){
            ans = false;
        }
    }*/
    cout << (ans ? "YES" : "NO");
    return 0;
}