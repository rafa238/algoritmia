//https://www.spoj.com/problems/TDPRIMES/
#include <bits/stdc++.h>

using namespace std;

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

int main(){
    int n = 100000000;
    vector<int> primes;
    primes = criba(n);
    for(int i=0; i<primes.size(); i+=100){
        cout<<primes[i]<<endl;
    }
    return 0;
}