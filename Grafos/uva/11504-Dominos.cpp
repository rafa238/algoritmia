#include <bits/stdc++.h>

using namespace std;
vector<vector<int>> AL, AL_T;
vector<int> dfs_num, s;

void kosaraju(int u, int pass){
    dfs_num[u] = 1;
    vector<int> &neighbor = (pass == 1) ? AL[u] : AL_T[u];
    for(int v : neighbor){
        if(dfs_num[v] == 0){
            kosaraju(v, pass);
        }
    }
    s.push_back(u);
}

void dfs(int u){
    dfs_num[u] = 1;
    for(auto v : AL[u]){
        if(dfs_num[v] == 0)
            dfs(v);
    }
}

int main(){
    int tc; cin>>tc;
    while(tc--){
        int N, m; cin>>N>>m;
        s.clear();
        dfs_num.assign(N+1, 0);
        AL.assign(N+1, vector<int>());
        AL_T.assign(N+1, vector<int>());

        for(int i=0; i<m; i++){
            int u, v; 
            cin>>u>>v;
            AL[u].push_back(v);
            AL_T[v].push_back(u);
        }

        for(int u=1; u<=N; u++){
            if(dfs_num[u] == 0)
                kosaraju(u, 1);
        }
        //int numSCC = 0;
        dfs_num.assign(N+1, 0);
        vector<int> roots;
        for(int i=N-1; i >= 0; i--){
            if(dfs_num[s[i]] == 0){
                //numSCC++;
                roots.push_back(s[i]);
                kosaraju(s[i], 2);
            }
        }

        int dominos = 0;
        dfs_num.assign(N+1, 0);
        for(auto root : roots){
            if(dfs_num[root] == 0){
                dominos++;
                dfs(root);
            }
        }
        
        cout<<dominos<<"\n";
    }
    return 0;
}