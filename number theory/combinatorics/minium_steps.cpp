//https://codeforces.com/problemset/problem/804/B
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll mod = 1000000007;

int pwr(long long x, int p){
    if (p == 0) return 1;
    if (p & 1) return x * pwr(x, p - 1) % mod;
    return pwr(x * x % mod, p >> 1) % mod;
}

int main(){
    string s; cin>>s;
    ll as = 0, bs = 0, ans = 0;

    for(auto ch: s) {
        if (ch == 'a') as++;
        else {
            ans += pwr(2, as) - 1;
            ans %= mod;
        }
    }
    cout << ans << endl;
    return 0;
}
