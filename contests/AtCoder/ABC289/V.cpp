#include<bits/stdc++.h>
using namespace std;
vector<bool> visited;
vector<int> graph;

bool miComparacion(int num1, int num2) {
  if (num1 < num2) {
    return false;
  } else {
     return true;
  }
}

void dfs(int node, vector<int> &res){
    visited[node] = true;
    res.push_back(node);
    if(graph[node] == -1) return;
    dfs(graph[node], res);
}

int main(){
    int n, m; cin>>n>>m;
    int edge;
    visited.assign(n+3, false);
    graph.assign(n+1, -1);

    for(int i=0; i < m; i++){
        cin>>edge;
        graph[edge] = edge+1;
    }

    for(int i=1; i<=n; i++){
        if(visited[i] == true) continue;
        vector<int> ans;
        dfs(i, ans);
        sort(ans.begin(), ans.end(), miComparacion);
        for(auto elem : ans){
            cout << elem << " ";
        }
    }

    return 0;
}