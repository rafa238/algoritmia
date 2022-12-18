//https://codeforces.com/gym/101879/problem/E
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
    vector<vector<ll>> t (31, vector<ll>(31));
    vector<ll> f(31);
    binomialCoeficients(30, t, f);

    int s; cin>>s;
    if(s<2) {cout<<"0"<<endl; return 0;}
    int ans=0;
    for(int i=2; i<=s; i++){
        ans += t[s][i];
    }
    cout<<ans<<endl;
    return 0;
}
