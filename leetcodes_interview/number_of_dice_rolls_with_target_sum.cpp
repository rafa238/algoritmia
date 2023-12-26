class Solution {
public:
    vector<vector<long long>> dp;
    const int MOD = 1e9 + 7;

    long long recursive(int &n, int currDice, int &k, long long currSum, int &target) {
        if (currDice == n && currSum == target) return 1LL;
        if (currDice > n || currSum > target) return 0LL;
        if (dp[currDice][currSum] != -1) return dp[currDice][currSum];

        long long answer = 0;
        for (int i = 1; i <= k; i++) {
            answer = (answer + recursive(n, currDice + 1, k, currSum + i, target)) % MOD;
        }
        dp[currDice][currSum] = answer;
        return answer;
    }

    int numRollsToTarget(int n, int k, int target) {
        dp.resize(n + 1, vector<long long>(target + 1, -1));
        long long answer = 0;
        for(int i = 1; i <= k; i++){
            answer = (answer + recursive(n, 1, k, i, target)) % MOD;
        }
        return answer;
    }
};