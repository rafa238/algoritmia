#include <bits/stdc++.h>
//https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=636&page=show_problem&problem=1626
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
    int c, r;
    while(cin>>c>>r){
        if(c == 0 && r == 0) break;
        map<string, int> creatures;
        for(int i=0; i<c; i++){
            string creature;
            cin>>creature;
            creatures[creature] = i;
        }
        UnionFind ds(c);
        for(int i=0; i<r; i++){
            string prey, predator;
            cin>>prey>>predator;
            ds.unionSet(creatures[prey], creatures[predator]);
        }
        int ans = INT_MIN;
        for(int i=0; i<c; i++){
            ans = max(ds.sizeOfSet(i), ans);
        }
        cout<<ans<<endl;
    }

    return 0;
}