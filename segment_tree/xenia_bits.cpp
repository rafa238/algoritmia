//https://codeforces.com/problemset/problem/339/D
#include <bits/stdc++.h>
using namespace std;
int levels;
struct SegmentTree{
    vector<int> t;
    
    SegmentTree(vector<int> &vals){
        int n= vals.size();
        t.resize(n*4);
        build(0, n-1, 1, vals, 0);
    }

    void build(int a, int b, int u, vector<int> &vals, int lvl){
        if(a==b){
            t[u] = vals[a];
            return;
        }
        int m = (a+b)/2;
        build(a, m, u*2, vals, lvl+1);
        build(m+1, b, u*2+1, vals, lvl+1);
        //operation
        if ((levels - lvl) & 1)
            t[u] = t[u*2] | t[u*2+1];
        else
            t[u] = t[u*2] ^ t[u*2+1];
    }

    void update(int a, int b, int u, int pos, int val, int lvl){
        if(a == b){
            t[u] = val;
            return;
        }
        int m = (a+b)/2;
        if(pos <= m){
            update(a, m, 2*u, pos, val, lvl + 1);
        } else {
            update(m+1, b, 2*u+1, pos, val, lvl + 1);
        }
        //operation
        if ((levels - lvl) & 1)
            t[u] = t[u*2] | t[u*2+1];
        else
            t[u] = t[u*2] ^ t[u*2+1];
    }
};


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int n, m; cin >> n >> m;
    levels = n;

    vector<int> a(1<<n);
    for (int i = 0; i < (1<<n); i++)
        cin >> a[i];
    
    SegmentTree T(a);

    while (m--) {
        int pos, val; cin >> pos >> val;
        pos --;

        T.update(0, (1<<n)-1, 1, pos, val, 0);
        cout << T.t[1] << endl;
    }
    return 0;
}