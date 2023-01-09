#include <bits/stdc++.h>
#define fstIO ios_base::sync_with_stdio(0); cin.tie(NULL);
using namespace std;

int N,M,K;
vector<vector<pair<int,int>>> adj;
int par[100005];
long long dist[100005];
long long edge[400005];
int relaxed[400005];

void dijkstra(){
    priority_queue<pair<long long, int> > q;
    for(int i=1; i <= N; ++i) dist[i] = (long long) LONG_LONG_MAX;
    for(int i=1; i <= N; ++i) par[i] = -1;
    dist[1] = 0;
    q.push(make_pair(dist[1], 1));
    while(!q.empty()){
        long long d = -q.top().first;
        int u = q.top().second;
        q.pop();
        if(d > dist[u])continue;
        for(int i=0;i<adj[u].size();++i){
            int v = adj[u][i].first;
            int e = adj[u][i].second;
            if(dist[v] > d + edge[e]){
                dist[v] = d + edge[e];
                par[v] = e;
                q.push(make_pair(-dist[v],v));
            } else if(dist[v] == d + edge[e]){
                if(e < M){
                    par[v] = e;
                }
            }
        }
    }
}

int main(){
    int u,v;
    long long w;
    cin >> N >> M >> K;
    adj = vector<vector<pair<int,int> > > (N+3);
    for(int i=0;i<M;++i){
        cin >> u >> v >> w; 
        adj[u].push_back(make_pair(v,i));
        adj[v].push_back(make_pair(u,i));
        edge[i] = w;
    }
    for(int i=0;i<K;++i){
        cin >> v >> w;
        adj[1].push_back(make_pair(v, i+M));
        adj[v].push_back(make_pair(1, i+M));
        edge[i+M] = w;
    }
    dijkstra();
    for(int i=1; i<=N; ++i){
        if(par[i] == -1)continue;
        relaxed[par[i]] = 1;
    }
    int ans = 0;
    for(int i=M;i<M+K;++i){
        if(!relaxed[i]) ++ans;
    }
    cout << ans;
    return 0;
}