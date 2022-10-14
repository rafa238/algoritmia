#include <bits/stdc++.h>
using namespace std;

vector<bool> isPrime;
vector<int> primes;
void criba(int n) {
    isPrime = vector<bool>(n, true);
    primes = vector<int>();
    isPrime[0] = isPrime[1] = false;
    for (int i=2; i<n; ++i) {
        if (isPrime[i]) {
            primes.push_back(i);
            for (int h=2; h*i<n; ++h) isPrime[i*h] = 0;
        }
    }
}

int main(){
    int n, k;
    cin>>n>>k;
    criba(n);
    
    cout<<ans<<endl;
    return 0;
}