#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    int N;cin >> N;
    int cpyN = N;
    vector<ll> discounts;
    map<ll, ll> needed;
    while(N--){
        ll a,b; cin>>a>>b;
        discounts.push_back(b);
        needed[b]+=a; 
    }
    sort(discounts.begin(), discounts.end());

    ll i = 0, j = cpyN  - 1, bought = 0, money = 0;
    while(i<j){
        if( discounts[j] <= bought || needed[discounts[j]] == 0){
            bought += needed[discounts[j]];
            money += needed[discounts[j]];
            j--;
        } else if ( discounts[i] <= bought){
            bought += needed[discounts[i]];
            money += needed[discounts[i]];
            i++;
        } else {
            ll requeridos = max(discounts[i]-bought, (ll)0);
            ll xComprar = min(requeridos, needed[discounts[j]]);
            bought += xComprar;
            money += (2 * xComprar);
            needed[discounts[j]] -= xComprar;
        }
    }
    
    if( discounts[i] <= bought){
        bought += needed[discounts[i]];
        money += needed[discounts[i]];
    } else {
        ll requeridos = max(discounts[i]-bought, (ll)0);
        ll xComprar = min(requeridos, needed[discounts[j]]);
        bought += xComprar;
        money += (2 * xComprar);
        needed[discounts[i]] -= xComprar;
        if(needed[discounts[i]] > 0){
            money += needed[discounts[i]];
            bought += needed[discounts[i]];
        }
    }
    cout<<money<<endl;
    return 0;
}