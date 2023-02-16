#include <iostream>
#include <cstdlib>
using namespace std;
typedef long long int ll;
ll Factorial(const ll);
ll Combinatorio(const ll, const ll);

int main(){
    ll n, k;
    while(scanf("%d %d", &n, &k) != -1){
        ll ans = Combinatorio(n+1,k);
        if(k == 0) k++;
        ans += k;
        ans %= 1000000007;
        cout<<ans<<endl;
    }
}

ll Factorial(const ll n){
    ll i, fact = 1;

    for (i = 2; i <= n; i++)
        fact = fact * i;

    return fact;
}

ll Combinatorio(const ll n, const ll m){
    return Factorial(n) / (Factorial(n - m) * Factorial(m));
}