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
    UnionFind ds(26);
    int slept; cin>>slept;
    getchar();
    int con; cin>>con;
    getchar();
    string wake; cin>>wake; 
    //cout<<'A'-wake[0]<<'A'-wake[1]<<'A'-wake[2];
    ds.unionSet(wake[0]-'A', wake[1]-'A');
    ds.unionSet(wake[1]-'A', wake[2]-'A');
    vector<vector<char>> graph(26);
    for(int i=0; i<con; i++){
        char c1,c2;
        cin>>c1>>c2;
        graph[c1-'A'].push_back(c2);
        graph[c2-'A'].push_back(c1);
    }
    for(auto v: graph){
        for(auto elem: v){
            cout<<elem<<" ";
        }
        cout<<endl;
    }
    return 0;
}
