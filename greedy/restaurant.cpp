//https://codeforces.com/problemset/problem/597/B
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<ll, ll> pii;

int main(){
    int n; cin>>n;
    vector<pii> orders(n);
    for(int i=0; i<n; i++){
        cin>>orders[i].second>>orders[i].first;
    }
    sort(orders.begin(), orders.end());
    ll l = orders[0].first;
    ll sol = 1;
    for(int i=1; i<n; i++){
        if(l<orders[i].second){
            l = orders[i].first;
            sol++;
        }
    }
    cout<<sol<<endl;
    return 0;
}