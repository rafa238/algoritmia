//https://leetcode.com/problems/subsets/
class Solution {
public:
    void backtrack(vector<int>&nums, vector<vector<int>> &ans, vector<int> &curr, int idx){
        if(idx <= nums.size()-1){
            ans.push_back(curr);
        }
        for(int i=idx+1; i<nums.size(); i++){
            curr.push_back(nums[i]);
            backtrack(nums, ans, curr, i);
            curr.pop_back();
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        ans.push_back({});
        for(int i=0; i<nums.size(); i++){
            vector<int> curr;
            curr.push_back(nums[i]);
            backtrack(nums, ans, curr, i);
        }
        return ans;
    }
};