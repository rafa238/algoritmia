#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<ll> criba(ll n){
    vector<ll> primes;
    vector<bool> is_prime(n+1, true);
    is_prime[0] = is_prime[1] = false;
    for(int i=2; i<=n; i++){
        if(is_prime[i]){
            primes.emplace_back(i);
            for(int j=2*i; j<=n; j+=i){
                is_prime[j] = false;
            }
        }
    }
    return primes;
}

int main(){
    ll n; cin>>n;
    //sqrt(10e12/12) es el valor maximo que puede tomar un primo
    vector<ll> primes = criba(sqrt(n/12LL)+2LL);
    int m = primes.size(), ans = 0;
    for(int i=0; i<m; i++){
        ll a = primes[i];
        for(int j=i+1; j<m; j++){
            ll b = primes[j];
            for(int k = j+1; k<m; k++){
                ll c = primes[k];
                if(
                    a*a > n ||
                    a*a*b > n ||
                    a*a*b*c > n ||
                    a*a*b*c*c > n
                ){
                    break;
                }
                ans++;
            }
        }
    }
    cout<<ans<<"\n";
    
    return 0;
}