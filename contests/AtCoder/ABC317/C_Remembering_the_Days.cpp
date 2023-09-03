#include <bits/stdc++.h>

using namespace std;
int ans;
vector<vector<int>> mat;
vector<bool> visited;

void dfs(int u, int cost){
    if(visited[u]) return;
    visited[u] = true;
    for(int i=1; i < 11; i++){
        if(mat[u][i] == 0) continue;
        dfs(i, cost + mat[u][i]);
    }
    ans = max(cost, ans);
    visited[u] = false;
}

int main(){
    mat.resize(11, vector<int>(11, 0));
    visited.resize(11, false);
    ans = INT_MIN;

    int n, m; cin>>n>>m;
    for(int i=0; i<m; i++){
        int u, v, cost;
        cin>>u>>v>>cost;
        mat[u][v] = mat[v][u] = cost;
    }
    for(int i=1; i<=n; i++){
        dfs(i, 0);
    }
    cout<<ans<<"\n";
    return 0;
}