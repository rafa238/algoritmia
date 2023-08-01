//https://leetcode.com/problems/contains-duplicate/submissions/
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> distincts;
        for(int num : nums){
            if (distincts.count(num) != 0){
                return true;
            }
            distincts.insert(num);
        }
        return false;
    }
};