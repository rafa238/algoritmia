//https://www.spoj.com/problems/ETF/
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll phi(ll n) {
    ll result = n;
    for (ll i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            while (n % i == 0)
                n /= i;
            result -= result / i;
        }
    }
    if (n > 1)
        result -= result / n;
    return result;
}

int main(){
    int tc;
    cin>>tc;
    ll num;
    while(tc--){
        cin>>num;
        cout<<phi(num)<<"\n";
    }
}