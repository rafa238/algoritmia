#include<bits/stdc++.h>
#define VISITED 1
#define UNVISITED 0
using namespace std;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef long long ll;

vector<vector<int>> adjList;
void bfs(int u, vi &visited){
    queue<int> q;
    q.push(u);
    while(!q.empty()){
        int curr = q.front();
        q.pop();
        for(int i=0; i<adjList[curr].size(); i++){
            int elem = adjList[curr][i];
            if(visited[elem] == UNVISITED){
                visited[elem] = VISITED;
                q.push(elem);
            }
        }
    }
}

int main(){
    int n; 
    while(cin>>n && n != 0){
        adjList.clear();
        adjList.resize(103, vector<int>());
        int initialNode;
        while(cin>>initialNode && initialNode != 0){
            int node;
            while(cin>>node && node != 0){
                adjList[initialNode].push_back(node);
            }
        }

        int numSources; cin>>numSources;
        
        for(int i=0; i<numSources; i++){
            vi visited(n+3, UNVISITED);
            int source; cin>>source;
            bfs(source, visited);
            //count unaccesible
            vi unaccesible;
            for(int i=1; i<=n; i++){
                if(visited[i] != VISITED){
                    unaccesible.push_back(i);
                }
            }
            //show unaccesible
            cout<<unaccesible.size();
            for(auto elem: unaccesible){
                cout<<" "<<elem;
            }
            cout<<endl;
        }
    }
    
    return 0;
}