#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int n; cin>>n;
    ll x, y, answer = 0;
    map<pair<ll, ll>, ll> repeated;
    map<ll, ll> xfreq;
    map<ll, ll> yfreq;
    
    while(n--){
        cin>>x>>y;
        xfreq[x]++;
        yfreq[y]++;
        repeated[make_pair(x, y)]++;
    }

    for(auto f:xfreq){
        answer += (f.second*(f.second-1))/2;
    }

    
    for(auto f:yfreq){
        answer += (f.second*(f.second-1))/2;
    }

    for(auto f:repeated){
        answer -= (f.second*(f.second-1))/2;
    }
    cout<<answer<<endl;
    return 0;
}