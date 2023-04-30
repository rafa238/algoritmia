#include <bits/stdc++.h>
//https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=636&page=show_problem&problem=2498
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
    int n, tc; cin>>tc;
    while(tc--){
        cin>>n;
        map<string, int> friendd;
        int index = 0;
        UnionFind ds(10e5 + 3);
        for(int i=0; i<n; i++){
            string s1, s2;
            cin>>s1>>s2;
            if(friendd.count(s1) == 0){
                friendd[s1] = ++index;
            }
            if(friendd.count(s2) == 0){
                friendd[s2] = ++index;
            }
            ds.unionSet(friendd[s1], friendd[s2]);
            cout<<ds.sizeOfSet(friendd[s1])<<endl;
        }
    }

    return 0;
}