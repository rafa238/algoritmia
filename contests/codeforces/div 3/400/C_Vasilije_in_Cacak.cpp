#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int tc; cin >> tc;
    while(tc--){
        ll n, k, x;
        cin>>n>>k>>x;
        ll min_sum = ((k)*(k+1)) / 2;
        ll total_sum = ((n)*(n+1)) / 2;
        ll max_sum = total_sum - ((n-k)*(n-k+1)) / 2;
        if(min_sum <= x && x <= max_sum){
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}