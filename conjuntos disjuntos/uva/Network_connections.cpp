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
    int T, n, x, y, conts, contf;
    char c;
    string s;
    scanf("%d", &T);

    for(int tc=1; tc<=T; tc++){
        scanf("\n%d\n", &n);
        UnionFind estruc(n+3);
        conts=contf=0;
        while(getline(cin, s)){
            if(s.length() == 0) break;
            sscanf(s.c_str(), "%c %d %d", &c, &x, &y);
            if(c=='c') estruc.unionSet(x, y);
            else if(c=='q'){
                bool ans = estruc.isSameSet(x, y);
                //cout<<ans;
                if(ans){ conts++;}
                else {contf++;}
            }
        }
        if(tc!=1) printf("\n");
        printf("%d,%d\n",conts,contf);
    }
    return 0;
}