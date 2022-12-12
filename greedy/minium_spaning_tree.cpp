#include <bits/stdc++.h>

using namespace std;

struct par{
    int nod, cost;
    bool operator < (const par &a) const{
        return cost > a.cost;
    }
};

int main(){
    int n, m; cin>>n>>m;
    priority_queue<par> q;

    vector<vector<par>> v(n+1, vector<par>());
    vector<int> vcost(n+1, INT_MAX);
    vector<bool> visited(n+1, false);
    
    for(int i=0; i<m; i++){
        int x,y,z; cin>>x>>y>>z;
        v[x].push_back(par{y, z});
        v[y].push_back(par{x, z});
    }

    q.push((par){1,0});
    int nod, cost, sol=0;
    while(!q.empty()){
        nod = q.top().nod; cost = q.top().cost;
        q.pop();
        if(visited[nod]) continue;
        visited[nod] = true;
        sol += cost;
        for(int i=0; i<(int)v[nod].size(); i++){
            int newn = v[nod][i].nod;
            int newc = v[nod][i].cost;
            if(!visited[newn] && vcost[newn] > newc){
                vcost[newn] = newc;
                q.push((par){newn, newc});
            }
        }
    }
    cout<<sol<<endl;
    return 0;
}