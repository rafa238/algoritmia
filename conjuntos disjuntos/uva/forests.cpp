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


int main(){
    int tc;    
    scanf("%d\n\n", &tc);
    while(tc--){
        int p, t, i, j;
        scanf("%d %d", &p, &t);
        vector<set<int>> graph(p+1);
        UnionFind dsu(p+1);
        vector<bool> visited(p, false);
        
        string s;
        getline(cin, s);
        while(getline(cin, s)){
            if(s.length() == 0) break;
            sscanf(s.c_str(), "%d %d", &i, &j);
            graph[i].insert(j);
            visited[i] = true;
        }

        for(int i=0; i<graph.size(); i++){
            for(int j=i+1; j<graph.size(); j++){
                if (graph[i] == graph[j])  dsu.unionSet(i, j);
            }
        }

        set<int> answer;
        for(int h=1; h<=p; h++){
            if(visited[p]) answer.insert(dsu.findSet(h));
        }
        printf("%d\n", answer.size());
        if(tc) printf("\n");
    }
    return 0;
}