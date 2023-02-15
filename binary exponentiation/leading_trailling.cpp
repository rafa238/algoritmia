//https://onlinejudge.org/index.php?option=onlinejudge&Itemid=99999999&page=show_problem&category=0&problem=1970
#include<bits/stdc++.h>
using namespace std;

long long binpow(long long a, long long b, long long m) {
    a %= m;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

int main(){
    long a, b, tc; cin >> tc;
    int fst, snd;
    long double product;
    while(tc--){
        cin>>a>>b;
        snd = binpow(a, b, 1000);
        
        product =(double)(b * log10(a));
        fst = pow(10, product - floor(product)) * 100;

        cout << fst << "..." << setw(3) << setfill('0') << snd << "\n";
    }
    return 0;
}