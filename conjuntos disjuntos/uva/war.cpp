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
    int N;
    scanf("%d", &N);
    UnionFind aliades(2*N);
    while(true){
        int op, c1, c2;
        scanf("%d %d %d", &op, &c1, &c2);
        if(op==0 && c1==0 && c2==0) break;
        int a1 = aliades.findSet(c1), a2 = aliades.findSet(c1 + N);
        int b1 = aliades.findSet(c2), b2 = aliades.findSet(c2 + N);
        switch(op){
            case 1:
                if(a1 == b2) puts("-1");
                else {
                    aliades.unionSet(c1, c2);
                    aliades.unionSet(c1+N, c2+N);
                }
                break;
            case 2:
                if(a1 == b1) puts("-1");
                else {
                    aliades.unionSet(c1, c2+N);
                    aliades.unionSet(c2, c1+N);
                }
                break;
            case 3:
                {
                    if(a1 == b1) cout<<"1"<<endl;
                    else cout<<"0"<<endl;
                    break;
                }
            case 4:
                if(a1 == b2) cout<<"1"<<endl;
                else cout<<"0"<<endl;
                break;
            default: break;
        }
    }
    
    return 0;
}