#include <bits/stdc++.h>
 
using namespace std;
vector<vector<int>> graph;
vector<unordered_set<int>> subsets;
vector<int> visited;
 
void bfs(int u){
    queue<int> q;
    q.push(u);
    while(!q.empty()){
        int curr = q.front();
        q.pop();
        if(visited[curr] == 1) continue;
        
        for(auto v : graph[curr]){
            for(int elem : subsets[v]){
                subsets[curr].insert(elem);
            }
            q.push(v);
        }
        visited[curr] = 1;
    }
}
 
int main(){
    int tc; cin>>tc;
    while(tc--){
        int n; cin >> n;
        graph.assign(n, vector<int>());
        subsets.assign(n, unordered_set<int>()); 
        degree.assign(n, 0);
        for(int i=0; i < n; i++){
            string elem; cin>>elem;
            for(int j=0; j < n; j++){
                if(elem[j] == '1'){
                    graph[j].push_back(i);
                    degree[i]++;
                }
            }
        }
        for(int i=0; i<n; i++){
            subsets[i].insert(i+1);
        }
        visited.assign(n, 0);
        for(int i=0; i<n; i++ )
            bfs(i);
        for(int i=0; i < n; i++){
            cout << subsets[i].size() << " ";
            for(auto sub : subsets[i]){
                cout << sub << " "; 
            }
            cout << "\n";
        }
        
        
    }
    return 0;
}
