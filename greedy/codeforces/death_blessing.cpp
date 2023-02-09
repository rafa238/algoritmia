#include <bits/stdc++.h>
// https://codeforces.com/contest/1749/problem/B
using namespace std;
typedef long long int ll;

int main(){
    int tc; cin >> tc;
    while(tc--){
        int n; cin >> n;
        vector<pair<ll, ll>> monsters(n);
        ll ans = 0;
        for( int i=0; i<n; i++){
            cin>>monsters[i].second;
            ans += monsters[i].second;
        }
        for( int i=0; i<n; i++){
            cin>>monsters[i].first;
            ans += monsters[i].first;
        }
        sort(monsters.begin(), monsters.end());
        ans -= monsters[n-1].first;
        cout<<ans<<endl;
    }
    return 0;
}