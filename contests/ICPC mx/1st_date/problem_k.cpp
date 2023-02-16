#include<bits/stdc++.h>
using namespace std;

int recur(int kilos, vector<int> &dp, vector<int> &mounts){
    
    if(kilos <= 0) return kilos;
    if(dp[kilos] != -30) return dp[kilos];
    int ans = INT_MIN;
    for (int i = 0; i < mounts.size(); i++){
        //cout<<kilos-mounts[i]<<endl;
        ans = max(ans, recur(kilos-mounts[i], dp, mounts));
        dp[kilos] = ans;
    }
    return ans;
}

int main(){
    int k, p;
    cin>>k>>p;
    vector<int> mounts;
    while(p--){
        int mount; cin>>mount;
        mounts.push_back(mount);
    }
    while(k--){
        int kilos; cin>>kilos;
        //cout<<kilos;
        vector<int> dp(kilos+1, -30);
        int ans = INT_MIN;
        ans = max(ans, recur(kilos, dp, mounts));
        cout<<abs(ans)<<endl;
    }
    return 0;
}

