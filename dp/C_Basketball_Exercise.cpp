#include<bits/stdc++.h>
//https://codeforces.com/contest/1195/problem/C
using namespace std;
typedef long long ll;

vector<vector<ll>> dp;
vector<vector<ll>> rows;
int n;

ll solve(int i, int j){
    ll curr = rows[i][j];
    if(j == n-1){
        return curr;
    }
    if(dp[i][j] != -1){
        return dp[i][j];
    }
    int newI = (i==0) ? 1 : 0;
    dp[i][j] = max(curr + solve(newI, j+1), solve(i, j+1));
    return dp[i][j];
}

int main(){
    cin>>n;
    dp.resize(2, vector<ll>(n, -1));
    rows.resize(2, vector<ll>(n));

    for(int i=0; i<n; i++){
        cin>>rows[0][i];
    }
    for(int i=0; i<n; i++){
        cin>>rows[1][i];
    }
    ll ans1 = solve(0, 0);
    ll ans2 = solve(1, 0);
    cout<<max(ans1, ans2)<<endl;
    return 0;
}