#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll tc, q, n, l, k, r;
    cin>>tc;
    while(tc--){
        cin>>n>>q;
        
        vector<ll> ps(n+3);
        ll num, sum = 0;
        for(int i=1; i<=n; i++){
            cin>> num;
            sum += num;
            ps[i] = sum;
        }
        while(q--){
            cin>>l>>r>>k;
            ll ans = ps[l-1] + ps[n] - ps[r] + (r-l+1)*k;
            cout<<((ans % 2 == 0) ? "NO" : "YES")<<endl;
        }
        
    }
    return 0;
}