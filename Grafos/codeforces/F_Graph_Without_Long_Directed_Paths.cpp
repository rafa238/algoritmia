#include <bits/stdc++.h>

using namespace std;
vector<vector<int>> graph;
vector<int> side;
int n, m;

bool isBipartite(){
    side.resize(n+1, -1);
    bool is_bipartite = true;
    queue<int> q;
    for (int st = 0; st <= n; ++st) {
        if (side[st] == -1) {
            q.push(st);
            side[st] = 0;
            while (!q.empty()) {
                int v = q.front();
                q.pop();
                for (int u : graph[v]) {
                    if (side[u] == -1) {
                        side[u] = side[v] ^ 1;
                        q.push(u);
                    } else {
                        is_bipartite &= side[u] != side[v];
                    }
                }
            }
        }
    }
    return is_bipartite;
}

int main(){
    cin>>n>>m;
    graph.resize(n+1, vector<int>());
    vector<pair<int, int>> edges(m);
    for(int i = 0; i<m; i++){
        int u, v;
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
        edges[i] = make_pair(u, v);
    }
    bool ans = isBipartite();
    cout<<(ans ? "YES" : "NO")<<"\n";
    if(ans){
        for(int i=0; i<m; i++){
            cout<<side[edges[i].first];
        }
    }
    return 0;
}