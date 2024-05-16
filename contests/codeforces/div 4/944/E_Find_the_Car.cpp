#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
void solve() {
    ll n, k, q;

    cin >> n >> k >> q;
    vector<ll> as, bs;
    as.push_back(0);
    bs.push_back(0);
    for(int i = 0; i<k; i++) {
        ll elem; cin >> elem;
        as.push_back(elem);
    }

    for(int i = 0; i<k; i++) {
        ll elem; cin >> elem;
        bs.push_back(elem);
    }
    while(q--) {
        ll target; cin >> target;
    
        //cout << target;

        int l = 0, r = k , ans ;
        while(l <= r) {
            int mid = l + (r-l) / 2;
            
            if(as[mid] <= target) {
                l = mid + 1;
                ans = mid;
            } else {
                r = mid - 1;
            }
        }
        if(target == as[ans]) {
            cout << bs[ans] << " ";
        } else {
            ll res = bs[ans] + (target - as[ans]) * (bs[ans+1]-bs[ans]) / (as[ans+1] - as[ans]);
            cout << res << " ";
        }
        
    }
}

int main(){
    int tc;
    cin >> tc;
    while(tc--) {
        solve();
        cout << endl;
    }

    return 0;
}