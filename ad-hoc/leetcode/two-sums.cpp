class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> restas;
        vector<int> vec;
        for(int i=0; i<nums.size(); i++){
            if(restas.count(nums[i])) {
                vec.push_back(restas[nums[i]]);
                vec.push_back(i);
                return vec;
            } else {
                int resta = target - nums[i];
                restas[resta] = i;   
                cout<<resta<<" : "<<restas[resta]<<"\n";
            }
        }
        return vec;
    }
};