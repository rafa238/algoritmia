#include<bits/stdc++.h>
#define fstIO ios_base::sync_with_stdio(0); cin.tie(0);
//https://www.spoj.com/problems/PESADA04/
using namespace std;
vector<vector<int>> graph;

int tsp(int n, int pos, int mask){
    if(mask == (1<<n)-1){
        return graph[pos][0];
    }
    int ans = INT_MAX;
    for(int nxt=0; nxt<n; nxt++){
        if((mask & (1<<nxt)) || nxt == pos) continue;
        ans = min(graph[pos][nxt] + tsp(n, nxt, (mask | (1<<nxt))), ans);
    }
    return ans;
}

int main(){
    fstIO;
    int tc;
    cin>>tc;
    while(tc--){
        int n;
        cin>>n;
        graph.resize(n+1, vector<int>(n+1));
        for(int i=0; i<n+1; i++){
            for(int j=0; j<n+1; j++){
                if(i==j){
                    graph[i][j] = 0;
                } else {
                    cin>>graph[i][j];       
                }
            }
        }
        cout<<tsp(n+1, 0, 1)<<endl;
    }
}