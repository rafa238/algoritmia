#include <bits/stdc++.h>
using namespace std;
vector<bool> isPrime;
vector<int> primes;
vector<int> n_primes;

int criba(int n) {
    int cont = 0;
    isPrime = vector<bool>(n, true);
    primes = vector<int>();
    n_primes = vector<int>(n*n, 0);
    isPrime[0] = isPrime[1] = false;
    for (int i=2; i<=n; i++) {
        if (isPrime[i]) {
            primes.push_back(i);
            for (int h=2; h*i<=n; h++) {
                isPrime[i*h] = false;
                n_primes[i*h]++;
            }
        }
        if(n_primes[i] == 2) cont++;
    }
    return cont;
}

int main(){
    int n;
    cin>>n;
    int ans = criba(n);
    cout<<ans<<endl;
    return 0;
}