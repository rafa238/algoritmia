class Solution {
public:
    vector<int> dp;
    int recursive(string &s, int index){
        if(index == s.size()) return 1;
        if(s[index] == '0') return 0;
        if(dp[index] != -1) return dp[index];

        int take1 = recursive(s, index+1);
        int take2 = 0;
        if(index + 1 < s.size()){
            int currNum = (s[index] - '0') * 10 + (s[index + 1] - '0');
            if(currNum <= 26)
                take2 = recursive(s, index+2);
        }

        dp[index] = take1 + take2;
        return dp[index];
    }

    int numDecodings(string s) {
        dp.resize(s.size(), -1);
        return recursive(s, 0);    
    }
};
