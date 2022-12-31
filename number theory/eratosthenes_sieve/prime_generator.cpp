//https://www.spoj.com/problems/PRIME1/
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

vector<int> criba(int n){
    vector<int> primos;
    vector<bool> not_prime(n+1);

    not_prime[0] = not_prime[1] = true;
    for(int i=3; i*i <= n; i += 2){
        if(not_prime[i] == false){
            for(int j = i*i; j <= n; j += 2 * i)
                not_prime[j] = true;
        }
    }
    primos.push_back(2);
    for(int i=3; i <= n; i += 2){
        if(not_prime[i] == false){
            primos.push_back(i);
        }
    }
    return primos;
}

vector<ll> criba_sobre_rango(ll a, ll b){
    vector<int> primos = criba(sqrt(b)+1);
    vector<bool> not_prime(b-a+1);
    for(int p: primos){
        ll primer_multiplo = p * max((ll)p, (a+p-1)/p);
        for(ll j=primer_multiplo; j<=b; j+=p){
            not_prime[j-a] = true;
        }
    }
    vector<ll> primos_rango;
    for(ll i=a;i<=b;i++){
        if(not_prime[i-a] == false){
            primos_rango.push_back(i);
        }
    }
    return primos_rango;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tc; cin>>tc;
    ll maxn = 1e9;
    
    while(tc--){
        int a, b; cin>>a>>b;
        vector<ll> primes = criba_sobre_rango(a,b);
        for(auto prime : primes){
            if(prime != 1)
                cout<<prime<<"\n";
        }
        cout<<"\n";
    }
    return 0;
}