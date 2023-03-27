#include<bits/stdc++.h>
//https://leetcode.com/problems/partition-equal-subset-sum/
using namespace std;

bool canPartition(vector<int>& nums) {
    int sum = 0;
    for(int num : nums){
        sum += num;
    }
    int t = sum / 2;
    if(sum%2 != 0){
        return false;
    }
    unordered_set<int> dp;
    dp.insert(0);
    for(int elem : nums){
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
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i=0; i<n; i++){
        cin>>nums[i];
    }
    cout<<canPartition(nums);
    return 0;
}