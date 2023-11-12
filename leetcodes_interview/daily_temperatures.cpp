//https://leetcode.com/problems/daily-temperatures/description/
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temps) {
        vector<int> nextWarmer(temps.size(), 0);
        stack<pair<int, int>> s; 
        s.push({temps[0], 0});
        for(int i = 1; i < temps.size(); i++){
            while(!s.empty() && s.top().first < temps[i]){
                nextWarmer[s.top().second] = i - s.top().second;
                s.pop();
            }
            s.push({temps[i], i});  
        }
        return nextWarmer;
    }
};