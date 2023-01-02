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
    int n, m; cin >> n >> m;
    int tc = 1;
    while(n != 0 && m != 0){
        UnionFind ds(n);
        while(m--){
            int i, j; cin>>i>>j;
            ds.unionSet(i, j);
            
        }
        set<int> parents;
        for(int i = 1; i <= n; i++){
            parents.insert(ds.findSet(i));
        }
        cout<<"Case "<< tc << ": "<<parents.size();  
        tc++;
        cin >> n >> m;
    }
    return 0;
}
