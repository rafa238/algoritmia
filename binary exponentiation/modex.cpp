//https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3671
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll binPow(ll a, ll b, ll mod){
    ll res = 1;
    while (b > 0) {
        if (b & 1)
            res = (res * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return res;
}

int main(){
    ll n, ans, a, b, mod;
    cin>>n;
    while(n--){
        cin >> a >> b >> mod;
        ans = binPow(a, b, mod);
        cout<< ans << endl;
    }
    cin>>n;
    return 0;
}