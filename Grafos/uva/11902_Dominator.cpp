#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

vector<vi> graph;
vector<vi> ans;

void dfs(int u, int cancel, vi &visited){
    visited[u] = 1;
    if(u == cancel) return;
    for(int i=0; i<graph[u].size(); i++){
        if(graph[u][i] == 0) continue;
        if(visited[i] == 1) continue;
        dfs(i, cancel, visited);
    }
}

void dfsReachables(int u, vi &visited){
    for(int i=0;i <graph[u].size(); i++){
        if(graph[u][i] == 0) continue;
        if(visited[i] == 1) continue;
        visited[i] = 1;
        dfsReachables(i, visited);
    }
}

void printLine(int n){
    cout<<"+";
    for(int j=0; j<n+n-1; j++){
        cout<<"-";
    }
    cout<<"+";
    puts("");
}

int main(){
    int tc, n; cin>>tc;
    for(int t = 1; t<=tc; t++){
        cin>>n;
        graph.clear();
        graph.resize(n, vector<int>(n));
        ans.clear();
        ans.resize(n, vector<int>(n));
        for(int i=0; i<graph.size(); i++){
            for(int j=0; j<graph[i].size(); j++){
                cin>>graph[i][j];
            }
        }
        vi reachables(n, 0);
        reachables[0] = 1;
        dfsReachables(0, reachables);

        for(int i=0; i<n; i++){
            vi visited(n, 0);
            dfs(0, i, visited);
            for(int j=0; j<n; j++){
                if(i==j) ans[i][j] = 1;
                else ans[i][j] = !visited[j];   
            }
        }
        //show answer
        cout<<"Case "<<t<<":\n";
        printLine(n);
        
        for(int i=0; i<ans.size(); i++){
            for(int j=0; j<ans[i].size(); j++){
                if(j == 0) cout<<"|";
                cout<<((ans[i][j] && reachables[j])?'Y':'N')<<"|";
            }
            cout<<"\n";
            if(i != n-1){
                printLine(n);
            }
        }
        printLine(n);
    }
    return 0;
}