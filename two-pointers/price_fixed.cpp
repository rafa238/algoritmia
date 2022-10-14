#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
bool comp (pair<ll, ll> a, pair<ll, ll> b){
    return  a.second > b.second;
}

int main(){
    int N;cin >> N;
    vector<pair<ll, ll>> product;
    while(N--){
        ll a,b; cin>>a>>b;
        product.push_back(make_pair(a, b));
    }
    sort(product.begin(), product.end(), comp);
    for(int i=0; i<product.size(); i++){
        cout<<product[i].second<<" ";
    }
    ll i = 0, j = N-1, bought = 0, money = 0;
    while(i<j){
        if( product[j].second <= bought || product[j].first == 0){
            bought += product[j].first;
            money += product[j].first;
            j--;
        } else if ( product[i].second <= bought){
            bought += product[i].first;
            money += product[i].first;
            i++;
        } else {
            ll requeridos = max(product[i].second -bought, (ll)0);
            ll xComprar = min(requeridos, product[j].first);
            bought += xComprar;
            money += (2 * xComprar);
            product[j].first -= xComprar;
        }
    }
    
    if( product[i].second <= bought){
        bought += product[i].first;
        money += product[i].first;
    } else {
        ll requeridos = max(product[i].second-bought, (ll)0);
        ll xComprar = min(requeridos, product[j].first);
        bought += xComprar;
        money += (2 * xComprar);
        product[i].first -= xComprar;
        if(product[i].first > 0){
            money += product[i].first;
            bought += product[i].first;
        }
    }
    cout<<money<<endl;
    return 0;
}

/*
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
*/