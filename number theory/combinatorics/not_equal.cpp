//https://atcoder.jp/contests/abc209/tasks/abc209_c?lang=en
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll mod = 1000000007;
int main(){
    int N; cin >> N;
    vector<int> C(N);
    for(int i = 0; i < N; i++) {
        cin >> C[i];
    }
    sort(C.begin(),C.end());
    ll ans = 1;
    for(int i = 0; i < N; i++) {
        ans = ans * max(0, C[i] - i) % mod;
    }
    cout << ans << endl;
}