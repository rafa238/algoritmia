#include<bits/stdc++.h>
#define fstIO ios_base::sync_with_stdio(0); cin.tie(NULL);

typedef long long ll;
using namespace std;

ll INF = LONG_LONG_MAX;
vector<vector<pair<ll, ll>>> adj;
ll edge[400005];

void dijkstra(int s, vector<ll> & d, vector<pair<int,ll>> & p) {
    int n = adj.size();
    d.assign(n, INF);
    p.assign(n, make_pair(-1, 0));
    vector<bool> u(n, false);

    d[s] = 0;
    for (int i = 0; i < n; i++) {
        int v = -1;
        for (int j = 0; j < n; j++) {
            if (!u[j] && (v == -1 || d[j] < d[v]))
                v = j;
        }

        u[v] = true;
        
        for(int j=0; j<adj[v].size(); j++ ){
            auto nodo = adj[v][j];
            int to = nodo.first;
            int len = edge[nodo.second];

            if (d[v] + len < d[to]) {
                d[to] = d[v] + len;
                p[to] = make_pair(v, nodo.second);
            }
        }
    }
}


int main(){
    fstIO;
    
    int n, m, k; 
    cin >> n >> m >> k;
    adj.assign(n+10, vector<pair<ll,ll>>());

    int u, v, x;
    for(int i = 0; i < m; i++){
        cin >> u >> v >> x;
        adj[u].push_back(make_pair(v, i));
        adj[v].push_back(make_pair(u, i));
        edge[i] = x;
    }

    for(int i=0; i < k; ++i){
        cin >> v >> x;
        adj[1].push_back(make_pair(v, i+m));
        adj[v].push_back(make_pair(1, i+m));
        edge[i+m] = x;
    }
    
    vector<ll> d; 
    vector<pair<int,ll>> p;
    dijkstra(1, d, p);
    int ans = k;
    for(auto elem: p){
        if(elem.second >= m){
            ans--;
        }
    }
    cout<<ans<<endl;
    return 0;
}

/*
vector<pair<int,ll>> restore_path(int s, int t, vector<pair<int,ll>> const& p) {
    vector<pair<int, ll>> path;

    for (int v = t; v != s; v = p[v].first)
        path.push_back(make_pair(v, p[v].second));
    path.push_back(make_pair(s, 0));

    reverse(path.begin(), path.end());
    return path;
}

*/