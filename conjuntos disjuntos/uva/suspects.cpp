#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

class UnionFind {
    //p -> parent respectivly
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
    int N, G;
    string s;
    while(true){
        scanf("%d %d", &N, &G);
        //printf("%d : %d\n", N, G);
        if(N==0 && G==0) break;

        UnionFind estruc(N);
        set<int> vec;
        int cont = 0, alumns, alumn;

        for(int i=0; i<G; i++){
            scanf("%d", &alumns);
             int previous = -1;
            for (int j=0; j<alumns; j++){
                scanf("%d", &alumn);
                if(previous != -1){
                    estruc.unionSet(alumn, previous);
                }
                vec.insert(alumn);
                previous = alumn;
            }
        }
        for(auto elem: vec){
            if(estruc.isSameSet(0, elem)){
                cont++;
            }
        }
        if(cont == 0) cont++;
        printf("%d\n", cont);
    }
    
    return 0;
}

