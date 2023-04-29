#include <bits/stdc++.h>
//https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=636&page=show_problem&problem=1549
using namespace std;
typedef vector<int> vi;
class UnionFind {
    //p -> parent respectivly
    //rank -> height of each conjunt
    private: 
        vi p, rank, sizes;
        int numSets;
    public:
        UnionFind(int N){
            rank.assign(N,0);
            p.assign(N, 0);
            sizes.assign(N, 1);
            numSets = N;
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
        int sizeOfSet(int i){
            return sizes[findSet(i)];
        }
        int numDijointSets(){
            return numSets;
        }
        void unionSet(int i, int j){
            if(!isSameSet(i, j)){
                int x = findSet(i) , y = findSet(j);
                if (rank[x] > rank[y]) swap(x, y); //x is the lower set
                p[x] = y;
                if (rank[x] == rank[y]) ++rank[y];
                sizes[y] += sizes[x];
                numSets--;                  
            }
        }
};

int main(){
    int tc, n, m, x, y;
    cin>>tc;
    while(tc--){
        cin>>n>>m;
        UnionFind ds(n+1);
        for(int i=0; i<m; i++){
            cin>>x>>y;
            ds.unionSet(x, y);
        }
        int ans = INT_MIN;
        for(int i=1; i<=n; i++){
            ans = max(ds.sizeOfSet(i), ans);
        }
        cout<<ans<<endl;
    }
    return 0;
}