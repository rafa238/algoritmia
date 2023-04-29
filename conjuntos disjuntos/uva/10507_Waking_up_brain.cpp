#include <bits/stdc++.h>
//https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=636&page=show_problem&problem=1448
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
    int n, connections;
    string awaken;
    while(cin>>n){
        UnionFind ds(27);
        vector<vector<int>> graph(26, vector<int>(26, 0));
        cin>>connections>>awaken;
        
        int pivot = awaken[0] - 'A';
        ds.unionSet(pivot, awaken[1] - 'A');ds.unionSet(pivot,awaken[2] - 'A');
        for(int i=0; i<connections; i++){
            string con;
            cin>>con;
            int fst = con[0] - 'A', snd = con[1] - 'A';
            graph[fst][snd] = 1;
            graph[snd][fst] = 1;
        }
        int days = 0;
        while(ds.sizeOfSet(pivot) != n){
            if(days > 26){
                break;
            }
            vector<int> xConnect;
            for(int i=0; i<26; i++){
                if(ds.isSameSet(i, pivot)) continue;
                int cont = 0;
                for(int j=0; j<26; j++){
                    if(graph[i][j] == 0) continue;
                    //count awaken nodes
                    if(ds.isSameSet(j, pivot)){
                        cont++;
                    }
                }
                if(cont >= 3){
                    xConnect.push_back(i);
                }
            }
            for(auto elem : xConnect){
                ds.unionSet(elem, pivot);               
            }
            days++;
        }
        if(days < 26){
            cout<<"WAKE UP IN, " << days <<", YEARS" <<endl;
        } else {
            cout<<"THIS BRAIN NEVER WAKES UP"<<endl;
        }
        
    }
    return 0;
}