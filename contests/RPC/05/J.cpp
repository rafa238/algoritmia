#include<bits/stdc++.h>

using namespace std;

bool canPartition(vector<int>& nums, int idxExclude) {
    int sum = 0;
    for(int i=0; i<nums.size(); i++){

        if(idxExclude == i) continue;
        sum += nums[i];
    }
    int t = sum / 2;
    if(sum%2 != 0){
        return false;
    }
    unordered_set<int> dp;
    dp.insert(0);
    for(int i=0; i<nums.size(); i++){
        if(i == idxExclude) continue;
        int elem = nums[i];
        unordered_set<int> s;
        
        for(int sumi : dp){
            if((sumi + elem) == t){
                return true;
            }
            s.insert(sumi + elem);
            s.insert(sumi);
        }
        dp.insert(s.begin(), s.end());
    }
    bool ans = dp.count(t);
    return ans;
}

int main(){
    int n; cin>>n;
    vector<int> v(n);
    for(int i=0;i<n; i++){
        cin>>v[i];
    }
    vector<int> ans;
    for(int i=0;i<n; i++){
        if(canPartition(v, i) ){
            ans.push_back(i+1);
        }
    }
    cout<<ans.size()<<endl;
    for(auto elem : ans){
        cout<<elem<<" ";
    }
    return 0;
}