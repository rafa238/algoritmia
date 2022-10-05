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
    UnionFind estruc(N);
    vector<int> enemies(N+1, -1);
    while(true){
        int op, c1, c2;
        scanf("%d %d %d", &op, &c1, &c2);
        if(op==0 && c1==0 && c2==0) break;
        switch(op){
            case 1:
                if(enemies[estruc.findSet(c1)] == estruc.findSet(c2)) cout<<"-1 "<<endl;
                else estruc.unionSet(c1, c2);
                break;
            case 2:
                if(estruc.isSameSet(c1, c2)) cout<<"-1"<<endl;
                else {
                    int p1 = estruc.findSet(c1), p2 = estruc.findSet(c2);
                    enemies[p1] = p2;
                    enemies[p2] = p1;
                }
                break;
            case 3:
                {
                    bool ans = estruc.isSameSet(c1, c2);
                    if(ans) cout<<"1"<<endl;
                    else cout<<"0"<<endl;
                    break;
                }
                
            case 4:
                if(enemies[estruc.findSet(c1)] == estruc.findSet(c2)) cout<<"1"<<endl;
                else cout<<"0"<<endl;
                break;
            default: break;
        }
    }
    
    return 0;
}