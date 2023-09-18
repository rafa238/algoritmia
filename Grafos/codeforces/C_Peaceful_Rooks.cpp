#include<bits/stdc++.h>

using namespace std;
vector<vector<int>> graph;
vector<int> color;
vector<int> parent;
int cycle_start, cycle_end;
int n, m;

bool dfs(int v) {
    color[v] = 1;
    for (int u : graph[v]) {
        if (color[u] == 0) {
            parent[u] = v;
            if (dfs(u))
                return true;
        } else if (color[u] == 1) {
            cycle_end = v;
            cycle_start = u;
            return true;
        }
    }
    color[v] = 2;
    return false;
}

int find_cycle() {
    int numCycles = 0;
    color.assign(n+1, 0);
    parent.assign(n+1, -1);
    cycle_start = -1;

    for (int v = 0; v < n; v++) {
        if (color[v] == 0 && dfs(v))
            numCycles++;
    }
    return numCycles;
}

int main(){
    int tc; cin>>tc;
    while(tc--){
        cin >> n >> m;
        int ans = m;
        graph.clear();
        graph.resize(n+1, vector<int>());
        for(int i=0; i<m; i++){
            int u, v; cin>>u>>v;
            if(u == v){
                ans--;
            } else {
                graph[u].push_back(v);
            }
        }
        int cycles = find_cycle();
        ans += cycles;
        cout<<ans<<"\n";
    }
    return 0;
}