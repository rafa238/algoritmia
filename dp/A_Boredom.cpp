#include<bits/stdc++.h>
#define fstIO ios_base::sync_with_stdio(0); cin.tie(0);
using namespace std;
typedef long long ll;

vector<ll> freq;
vector<ll> dp;
ll MAXN = 10e3;

ll solve(int i){
    if(i>MAXN) return 0;
    if(dp[i] != LLONG_MIN) return dp[i];
    dp[i] = max(solve(i+1), freq[i]*i + solve(i+2));
    return dp[i];
}


int main(){
    fstIO;
    ll n, num;
    freq.resize(MAXN + 5, 0);
    dp.resize(MAXN+5, LLONG_MIN);
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>num;
        freq[num]++;
    }
    cout<<solve(1);
    return 0;
}