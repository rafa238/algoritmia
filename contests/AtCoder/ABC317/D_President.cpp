#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    int n; cin>>n;
    
    vector<int> xs(n), ys(n), zs(n);
    int zSum = 0;
    for(int i=0; i<n; i++){
        cin >> xs[i] >> ys[i] >> zs[i];
        zSum += zs[i];
    }
    vector<ll> dp(zSum + 1, (ll)1e18);
    dp[0] = 0;
    for(int i=0; i<n; i++){
        int x = xs[i], y = ys[i], z = zs[i];
        int w = max(0, (y + x) / 2 + 1 - x);
        for(int j=zSum; j>=z; j--){
            dp[j] = min(dp[j], dp[j-z] + w);
        }
    }
    ll ans = LONG_LONG_MAX;
    for(int i=(zSum)/2 + 1; i <= zSum; i++){
        ans = min(ans, dp[i]);
    }
    cout<<ans<<" ";
    return 0;
}