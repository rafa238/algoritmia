#include <bits/stdc++.h>
//https://onlinejudge.u-aizu.ac.jp/problems/DPL_1_C
using namespace std;

vector<vector<int>> dp;
//pairs value, weight
vector<pair<int, int>> values;
int n, w;

void solve(){
    for(int i=1; i<=n; i++){
        pair<int, int> currObj = values[i];
        for(int j=1; j<=w; j++){
            if(j >= currObj.second){
                int idx = j - currObj.second;
                dp[i][j] = max (dp[i][idx] + currObj.first, dp[i-1][j]); 
            } else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }
}

int main(){
    int vi, wi;
    cin>>n>>w;
    dp.resize(n+1, vector<int>(w+3, 0));
    values.resize(n+1);
    for(int i=1; i<=n; i++){
        cin>>vi>>wi;
        values[i] = make_pair(vi, wi);
    }
    solve();
    /*for(int i=0; i<=n; i++){
        for(int j=0; j<=w; j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }*/
    cout<<dp[n][w]<<endl;
    return 0;
}