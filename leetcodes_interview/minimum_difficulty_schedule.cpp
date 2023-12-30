class Solution {
public:
    const int INF = 999999;
    vector<vector<int>> dp;
    int solve(int index, int d, vector<int>& jobDifficulty) {
        
        if(d == 0 || index == jobDifficulty.size()) {
            if(d == 0 && index == jobDifficulty.size()) 
                return 0;
            else 
                return INF;
        }
        if(dp[d][index] != -1) return dp[d][index];
        int jobMaximum = jobDifficulty[index], answer = INF;

        for(int i = index; i < jobDifficulty.size(); i++) {
            jobMaximum = max(jobMaximum, jobDifficulty[i]);
            answer = min(answer, jobMaximum + solve(i + 1, d-1, jobDifficulty));
        }
        dp[d][index] = answer;
        return answer;
    }
    
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        dp.resize(d+1, vector<int>(jobDifficulty.size() + 3, -1)); 
        int answer = solve(0, d, jobDifficulty);
        return (answer == INF) ? -1 : answer;
    }
};