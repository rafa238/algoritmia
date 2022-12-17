//https://lightoj.com/problem/rooks
#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

void binomialCoeficients(int n, vector<vector<ll>> &t, vector<ll> &f){
    t[0][0] = f[0] = 1;
    for (int i = 1; i <= n; i++) {
        f[i] = f[i - 1] * i;
        t[i][0] = 1;
        for (int j = 1; j <= i; j++) {
            t[i][j] = t[i - 1][j - 1] + t[i - 1][j];
        }
    }
}

int main(){
    int tc; cin>>tc;
    vector<vector<ll>> t (31, vector<ll>(31));
    vector<ll> f(31);
    binomialCoeficients(30, t, f);
    for(int i=1; i<=tc; i++){
        int n, k; cin >> n >> k;
        cout << "Case " << i << ": ";
        if (k > n)
            cout << "0" << endl;
        else
            cout << t[n][k] * t[n][k] * f[k] << endl;
    }
    return 0;
}
