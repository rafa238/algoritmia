#include<bits/stdc++.h>
#define fstIO ios_base::sync_with_stdio(0); cin.tie(0);
//https://codeforces.com/gym/101873/problem/I
using namespace std;

vector<int> players, dp;
int n, m;

int solve(int pos, int currKills){
    if(pos >= n) return 0;
    if(dp[pos] != -1) return dp[pos];
    int ans = max(solve(pos+1, currKills), players[pos] + solve(pos+m, currKills));
    dp[pos] = ans;
    return ans;
}

int main(){
    fstIO;
    cin>>n>>m;
    dp.resize(n+1, -1);
    players.resize(n);
    for(int i=0; i<n; i++){
        cin>>players[i];
    }
    cout<<solve(m, 0);
    return 0;
}