#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int gcd(int a, int b, int& x, int& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    int x1, y1;
    int d = gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}

long long C(int n, int r, int MOD){
    vector<long long> f(n + 1,1);
    for (int i=2; i<=n;i++)
        f[i]= (f[i-1]*i) % MOD;
    return ();
 
int main(){
    int tc;
    cin>>tc;
    ll a,b;
    while(tc--){
        cin>>a>>b;
        ll MOD = 10e9 + 7;
        ll ans = C(a, b)%MOD;
        printf("%lld\n", ans);
    }
}