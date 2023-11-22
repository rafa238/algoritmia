//https://leetcode.com/problems/trapping-rain-water/description/
class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> maxLeft(height.size()), maxRight(height.size());
        maxLeft[0]  = maxRight[height.size() - 1] = 0;
        int maxium = INT_MIN;
        for(int i = 1; i < height.size(); i++){
            maxium = max(maxium, height[i-1]);
            maxLeft[i] = maxium;
        }
        maxium = INT_MIN;
        for(int i = height.size() - 2; i >= 0; i--){
            maxium = max(maxium, height[i+1]);
            maxRight[i] = maxium;
        }

        int water = 0;
        for(int i = 0; i<height.size(); i++){
            int waterBorder = min(maxRight[i], maxLeft[i]);
            if(waterBorder > height[i]){
                water += waterBorder - height[i]; 
            }
        }
        return water;
    }
};