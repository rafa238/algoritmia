class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int totalTime = 0;
        stack<pair<char, int>> ballons;
        for (int i = 0; i < colors.size(); i++) {
            if(!ballons.empty() && ballons.top().first == colors[i]) {
                if(ballons.top().second > neededTime[i]){
                    totalTime += neededTime[i];
                    continue;
                } else {
                    totalTime += ballons.top().second;
                    ballons.pop();
                }
            }
            ballons.push({colors[i], neededTime[i]});
        }
        return totalTime;
    }
};