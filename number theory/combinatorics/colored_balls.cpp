//https://codeforces.com/problemset/problem/553/A
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll mod = 1000000007;

void binomialCoeficients(int n, vector<vector<ll>> &t){
    t[0][0]  = 1;
    for (int i = 1; i <= n; i++) {
        t[i][0] = 1;
        for (int j = 1; j <= i; j++) {
            t[i][j] =( t[i - 1][j - 1] + t[i - 1][j]) % mod;
        }
    }
}

int main(){
    vector<vector<ll>> t (1003, vector<ll>(1003));
    binomialCoeficients(1002, t);

    int k; cin>>k;
    vector<int> color(k);
    for(int i=0;i<k;i++) cin>>color[i];

    ll result = 1;
    ll tota_balls = 0;
    for(int i=0; i < k; i++) {
        tota_balls += (ll)color[i];
        result *= (t[tota_balls-1][color[i]-1]);
        result %= mod;
    }
    cout << (result%mod) << endl;
    return 0;
}
