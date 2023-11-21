//https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/description/
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int index1 = 0, index2 = numbers.size() - 1;
        int currSum = numbers[index1] + numbers[index2];
        while( currSum != target){
            if(currSum < target){
                index1++;
            } else {
                index2--;
            }
            currSum = numbers[index1] + numbers[index2];
        }

        return {index1 + 1, index2 + 1};
    }
};