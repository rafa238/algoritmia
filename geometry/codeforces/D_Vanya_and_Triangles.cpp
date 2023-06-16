#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll comb(ll n, ll k) {
    ll res = 1;
    for (int i = n - k + 1; i <= n; ++i)
        res *= i;
    for (int i = 2; i <= k; ++i)
        res /= i;
    return res;
}

ll comb(ll num){
    if(num<3) return 0;
    if(num==3) return 1;
    return (num*(num-1)*(num-2))/6;
}

ll combK2(ll num){
    if(num<2) return 0;
    if(num==2) return 1;
    return (num*(num-1))/2;
}

pair<ll ,ll> pendient(pair<int, int> p1, pair<int ,int> p2){
    int a = p2.second-p1.second;
    int b = p2.first - p1.first;
    ll gc = __gcd(a, b);
    return make_pair((a)/gc, (b)/gc);
}

int main(){
    ll n; cin>>n;
    vector<pair<int, int>> points(n);
    for(ll i=0; i<n; i++){
        int x, y;
        cin>>x>>y;
        points[i] = make_pair(x, y);
    }
    sort(points.begin(), points.end());

    int countColinears = 0;
    for(ll i=0; i<points.size(); i++){
        map<pair<int, int>, int> freq;
        for(ll j=i+1; j<points.size(); j++){
            pair<int, int> p1 = points[i], p2 = points[j];
            pair<int, int> m = pendient( p1, p2);
            freq[m]++;
        }
        for(pair<pair<int, int>, int> elem : freq){
            countColinears += combK2(elem.second); 
        }
    }
    ll ans = comb(n) - countColinears;
    cout<<ans;
    return 0;
}