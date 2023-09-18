#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<int>> graph;
vector<int> side;

bool isBipartite(){
    bool isBipartite = true;
    side.resize(n+1, -1);
    queue<int> q;
    for(int st = 0; st<=n; st++){
        if(side[st] != -1) continue;
        q.push(st);
        side[st] = 0;
        while(!q.empty()){
            int u = q.front();
            q.pop();
            for(int v : graph[u]){
                if(side[v] == -1){
                    q.push(v);
                    side[v] = side[u]^1;
                } else {
                    isBipartite &= side[v] != side[u];
                }
            }
        }
    }
    return isBipartite;
}

int main(){
    cin >> n >> m;
    graph.resize(n+1, vector<int>());
    for(int i=0; i<m; i++){
        int u, v;
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    bool ans = isBipartite();
    if(ans){
        int color1 = 0, color2 = 0;
        for(int i=1; i<=n; i++){
            if(side[i] == 0){
                color1++;
            } else
                color2++;
        }

        cout<<color1<<"\n";
        for(int i=1; i<=n; i++){
            if(side[i] == 0)
                cout<<i<<" ";
        }
        cout<<"\n";
        cout<<color2<<"\n";
        for(int i=1; i<=n; i++){
            if(side[i] == 1)
                cout<<i<<" ";
        }
    } else 
        cout<<"-1";
    return 0;
}