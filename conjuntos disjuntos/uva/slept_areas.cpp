#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

class UnionFind {
    //p -> parent respectively
    //rank -> height of each conjunt
    private: vi p, rank;
    public:
        UnionFind(int N){
            rank.assign(N,0);
            p.assign(N, 0);
            for(int i=0; i<N; i++){
                p[i] = i;
            }
        }
        int findSet(int i){
            return (p[i] == i) ? i : (p[i] = findSet(p[i]));
        }
        bool isSameSet(int i, int j){
            return findSet(i) == findSet(j);
        }
        void unionSet(int i, int j){
            if(!isSameSet(i, j)){
                int x = findSet(i) , y = findSet(j);
                if(rank[x] > rank[y]) p[y] = x;
                else {
                    p[x] = y;
                    if(rank[x] == rank[y]) rank[y]++;
                }
            }
        }
};

UnionFind ds(26);

void bfs(vector<vector<char>> &graph, char start, char pivot){
    vector<bool> visited(26+3, false);
    vector<int> state(26+3, 0);
    queue<char> q;
    visited[start-'A'] = true;
    q.push(start);
    while(!q.empty()){
        int curr = q.front();
        q.pop();
        bool isAwake = ds.isSameSet(curr-'A', pivot-'A');
        for(auto child : graph[curr - 'A']){
            if(isAwake) state[child-'A']++;
            if(state[child-'A'] >= 3) ds.unionSet(child - 'A', pivot - 'A');
            if(visited[child - 'A']) continue;
            visited[child - 'A'] = true;
            q.push(child);
        }
    }
}

int main(){
    int slept; cin>>slept;
    int con; cin>>con;
    getchar();

    string wake; cin>>wake; 
    ds.unionSet(wake[0]-'A', wake[1]-'A');
    ds.unionSet(wake[1]-'A', wake[2]-'A');
    vector<vector<char>> graph(26);
    set<char> areas;
    for(int i=0; i<con; i++){
        char c1,c2;
        cin>>c1>>c2;
        areas.insert(c1);
        areas.insert(c2);
        graph[c1-'A'].push_back(c2);
        graph[c2-'A'].push_back(c1);
    }
    for(int i=0; i < 26+1; i++){
        bfs(graph, wake[0], wake[0]);
    }
    /*for(auto v: graph){
        for(auto elem: v){
            cout<<elem<<" ";
        }
        cout<<endl;
    }*/
    return 0;
}
