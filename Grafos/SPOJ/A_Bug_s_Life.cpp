#include <bits/stdc++.h>

using namespace std;
int n, m;
vector<vector<int>> graph;

bool isBipartite(){
    vector<int> side(n+1, -1);
    bool isBipartite = true;
    queue<int> q;
    for(int i=0; i <= n; i++){
        if(side[i] != -1) continue;
        side[i] = 0;
        q.push(i);
        while(!q.empty()){
            int u = q.front();
            q.pop();
            for(auto v : graph[u]){
                if(side[v] == -1){
                    side[v] = side[u]^1;
                    q.push(v);
                } else {
                    isBipartite &= side[u] != side[v];
                }
            }
        }
    }
    return isBipartite;
}

int main(){
    int tc; cin>>tc;
    for(int t = 1; t<=tc; t++){
        cin>>n>>m;
        graph.clear();
        graph.resize(n+1, vector<int>());
        for(int i=0; i<m; i++){
            int u, v;
            cin >> u >> v;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        bool ans = isBipartite();
        cout << "Scenario #" << t << ":\n";
        if(ans){
            cout<<"No suspicious bugs found!\n";
        } else {
            cout<<"Suspicious bugs found!\n";
        }
    }
    return 0;
}