#include<bits/stdc++.h>
using namespace std;
vector<int> dp;
vector<int> earn;
vector<pair<int, int>> abss;
int n;

int solve(int idx){
    if(idx > n) return 0;
    if(dp[idx] != -1) {
        return dp[idx];
    }
    int ans = INT_MIN;
    pair<int, int> bounds = abss[idx];
    for(int i=idx+bounds.first; i <= idx+bounds.second; i++){
        ans = max(earn[idx] + solve(i), ans);
    }
    dp[idx] = ans;
    return ans;
}

int main(){
    int g, a, b;
    cin>>n;
    dp.resize(n+1, -1);
    earn.resize(n+1);
    abss.resize(n+1);
    for(int i=1; i<=n; i++){
        cin>>g>>a>>b;
        abss[i] = make_pair(a, b);
        earn[i] = g;
    }
    int ans = INT_MIN;
    for(int i=1; i<=n; i++){
       ans = max(solve(i), ans);
    }
    cout<<ans<<endl;
    return 0;
}