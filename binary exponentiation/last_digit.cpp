//https://www.spoj.com/problems/LASTDIG/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll binPow(ll a, ll b){
    ll res = 1;
    while(b>0){
        if(b&1){
            res = res*a % 10;
        }
        b>>=1;
        a = a*a % 10;
    }
    return res;
}

int main(){
    int tc; cin >> tc;
    ll a, b, ans;
    while(tc--){
        cin >> a >> b;
        ans = binPow(a, b);
        cout << ans << endl;
    }
    return 0;
}