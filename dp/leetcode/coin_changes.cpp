#include <bits/stdc++.h>
//https://leetcode.com/problems/coin-change/
using namespace std;

int coinChange(vector<int>& coins, int amount) {
    sort(coins.begin(), coins.end());
    const int inf = 10e5;
    vector<int> dp(amount+1, inf);
    dp[0] = 0;
    for(int coin : coins){
        for(int i=1; i<=amount; i++) {
            int idx = i-coin;
            if(idx == 0){
                dp[i] = min(1, dp[i]);
            } else if (idx > 0){ 
                dp[i] = min(dp[idx] + 1, dp[i]);
            }
        }
    }
    int ans = (dp[amount] == inf) ? -1 : dp[amount];
    return ans;
}

int main(){
    int n, mount;
    cin>>n>>mount;
    vector<int> coins(n);
    for(int i=0; i<n; i++){
        cin>>coins[i];
    }
    cout<<coinChange(coins, mount);
    return 0;
}