#include <bits/stdc++.h>

using namespace std;


int main(){
    int tc; cin >> tc;
    while(tc--) {
        long long n, k;
        cin >> n >> k;
        long long left_side  = n-k+1;
        long long until_k = (n * (n+1)) / 2LL, 
                until_n = (left_side * (left_side - 1)) / 2;
        long long total_sum  =until_n - until_k;
        if(total_sum % 2 == 0) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}