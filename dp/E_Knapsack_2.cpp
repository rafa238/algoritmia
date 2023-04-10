#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
vector<ll> dp;
//pairs value, weight
vector<pair<ll, ll>> values;
ll n, w;

void solve(ll maxVal){
    
    for(ll i=0; i<n; i++){
        pair<ll, ll> curr = values[i];
        for(ll j=maxVal-curr.first; j>=0; j--){
            dp[j + curr.first] = min(dp[j+curr.first], dp[j]+curr.second);
        }
    }
    ll ans = INT_MIN;
    for(ll i=0;i<=maxVal;i++){
        if(dp[i] <= w)
            ans = max(ans, i);
    }

    cout<<ans<<endl;
}

int main(){
    
    cin>>n>>w;
    
    values.resize(n);
    ll maxVal = 0;
    for(ll i=0; i<n; i++){
        ll vi, wi;
        cin>>wi>>vi;
        values[i] = make_pair(vi, wi);
        maxVal += vi;
    }
    //sort(values.begin(), values.end());
    dp.resize(maxVal+1, INT_MAX);
    dp[0] = 0;
    solve(maxVal);
    return 0;
}