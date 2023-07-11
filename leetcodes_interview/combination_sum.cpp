//https://leetcode.com/problems/combination-sum/
class Solution {
public:
    void backTrack(vector<vector<int>>& ans, vector<int>& curr, int target, vector<int>& candidates, int index) {
        if (target < 0) {
            return;
        }
        if (target == 0) {
            ans.push_back(curr);
            return;
        }
        for (int i = index; i < candidates.size(); i++) {
            curr.push_back(candidates[i]);
            backTrack(ans, curr, target - candidates[i], candidates, i);
            curr.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> curr;
        backTrack(ans, curr, target, candidates, 0);
        return ans;
    }
};
