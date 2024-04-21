#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;

bool waterFits(ll target, ll height, vector<ll> &corals) {
    ll total_water = 0;
    for(auto &coral : corals) {
        ll ans = height - coral;
        total_water += max(0LL, ans); // Se añade agua según la diferencia entre la altura del tanque y la altura del coral
    }
    return total_water <= target; // Se retorna verdadero si la cantidad total de agua es menor o igual al límite
}
 
 
void solve(){
    ll n, target;
    cin >> n >> target;
    vector<ll> corals(n);
    for(auto &elem : corals) {
        cin >> elem;
    }
    ll low = 0, high = 10e12, ans;
    while(low <= high) {
        ll mid = (low + high) / 2LL;
 
        if(waterFits(target, mid, corals)) {
            //if water fits, we need to increase
            ans = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    cout << ans << endl;
}
 
int main(){
    ll tc; cin >> tc;
    while(tc--) {
        solve();
    }
    return 0;
}