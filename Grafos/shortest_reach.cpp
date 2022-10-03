//https://www.hackerrank.com/challenges/ctci-bfs-shortest-reach/problem
#include <bits/stdc++.h>

using namespace std;

vector<int> bfs(int n, int start, vector<vector<int>> &graph){
    vector<int> state(n+1, -1);
    vector<bool> visited(n+1, false);
    queue<int> q;
    q.push(start);
    state[start] = 0;
    visited[start] = true;

    while(!q.empty()){
        int f = q.front();
        q.pop();

        //cout<<"front:" << f << " " << graph[f].size() <<endl;
        
        for (int i = 0; i < graph[f].size(); i++){
            if(visited[graph[f][i]]) continue;
            state[graph[f][i]] = state[f] + 6;
            q.push(graph[f][i]);
            visited[graph[f][i]] = true;
        }
    }
    return state;
}

int main(){
    int Q; cin>>Q;
    while(Q--){
        int n, m; 
        cin>> n >> m;
        vector<vector<int>> graph(n+1);
        for (int i = 0; i < m; i++){
            int k,l;
            cin>>k>>l;
            graph[k].push_back(l);
            graph[l].push_back(k);
        }
        int s; cin>>s;
        vector<int> ans = bfs(n, s, graph);
        for (int i = 1; i < ans.size(); i++){
            if(i == s) continue;
            cout << ans[i] << " ";
        }
        cout<<endl;
        
        /*for (int i = 0; i < graph.size(); i++){
            cout << i << " : ";
            for (int j = 0; j < graph[i].size(); j++){
                cout<<graph[i][j];
            }
            cout<<endl;
        }*/
    }
    return 0;
}