#include <bits/stdc++.h>
using namespace std;
vector<bool> isPrime;
vector<int> primes;
vector<int> n_primes;
vector<int> almost_primes;

void criba(int n) {
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
        if(n_primes[i] == 2) almost_primes.push_back(i);
    }
}

int main(){
    int tc; cin>>tc;
    int maxn =  2000000;
    criba(maxn);
    while(tc--){
        int n;
        cin>>n;
        
        cout<<almost_primes[n]<<endl;
    }
    
    return 0;
}