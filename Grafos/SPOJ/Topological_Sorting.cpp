#include <bits/stdc++.h>

using namespace std;
vector<vector<int>> graph;
vector<int> in_degree, ts;
int n, m; 
void topo_sort(bool &exist){
    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i = 1; i<in_degree.size(); i++){
        if(in_degree[i] == 0){
            pq.push(i);
        }
    }
    int contNodes = 0;
    while(!pq.empty()){
        int u = pq.top();
        pq.pop();
        for(auto v : graph[u]){
            if(--in_degree[v] == 0){
                pq.push(v);
            }
        }
        ts.push_back(u);
        contNodes++;
    }
    if(contNodes != n){
        exist = false;
    }
}

int main(){
    cin>>n>>m;
    graph.assign(n + 1, vector<int>());
    in_degree.assign(n+1, 0);

    for(int i=0; i<m; i++){
        int u, v; cin>>u>>v;
        graph[u].push_back(v);
        in_degree[v]++;
    }
    bool exist = true;
    topo_sort(exist);
    if(exist){
        for(auto elem : ts){
            cout << elem << " ";
        }
        cout<<"\n";
    } else {
        cout << "Sandro fails.\n";
    }
    return 0;
}