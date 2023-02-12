#include <bits/stdc++.h>
// https://codeforces.com/problemset/problem/630/I
using namespace std;
typedef long long int ll;
long long binPow(long long a, long long b){
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}

int main(){
    int n; cin>>n;
    ll a = 3*n-1;
    ll aa=n-3;
    ll ans=a*3*binPow(4,aa);
    cout << ans << endl;
    return 0;
}