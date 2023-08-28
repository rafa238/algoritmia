class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int p = 0, p2 = 0;
        while(p2 != nums.size()){
            if(nums[p2] != 0){
            nums[p] = nums[p2];
            p++;
            }
            p2++;
        }

        while(p != nums.size()){
            nums[p] = 0;
            p++;
        }
        
    }
};