#include <bits/stdc++.h>

using namespace std;
vector<vector<int>> graph;
int n; 
vector<int> side;
bool isBipartite(){
    side.resize(n, -1);
    bool is_bipartite = true;
    queue<int> q;
    for (int st = 0; st < n; ++st) {
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
    
    
    cin >> n;
    graph.resize(n, vector<int>());
    vector<char> s(n);
    for(auto &c : s) cin>>c;

    for(int i=0; i<n; i++){
        for(int j=0; j<i; j++){
            if(s[j] > s[i]){
                graph[i].push_back(j);
                graph[j].push_back(i);
            }
        }
    }
    // for(auto i : graph){
    //     for(auto elem : i){
    //         cout<< elem <<" ";
    //     }
    //     cout<<"\n";
    // }
    bool ans = isBipartite();
    cout<<( (ans) ? "YES" : "NO")<<"\n";
    if(ans){
        for(auto elem : side){
            cout<<elem;
        }  
    }
    
    
    return 0;
}