class Solution {
public:
    int jump(vector<int>& nums) {
        queue<int> indexes;
        vector<int> lowest_distance(nums.size(), -1);
        indexes.push(0);
        lowest_distance[0] = 0;
        int curr_level = 1;
        while(!indexes.empty()){
            int level_size = indexes.size();
            for(int i = 0; i < level_size; i++){
                int curr = indexes.front();
                for(int j = curr + 1; j <= min(curr + nums[curr], (int)nums.size()-1); j++){
                    if(lowest_distance[j] != -1) continue;
                    lowest_distance[j] = curr_level;
                    indexes.push(j);
                }
                indexes.pop();
            }
            curr_level++;
        }
        return lowest_distance.back();
    }
};