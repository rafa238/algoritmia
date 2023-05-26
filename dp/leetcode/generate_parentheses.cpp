//https://leetcode.com/problems/generate-parentheses/description/
class Solution {
public:

    void search(int open, int closed, int t, vector<string> &ans, string curr){
        if(open == closed){
            search(open+1, closed, t, ans, curr+"(");
            return;
        }
        if(open == t){
            for(int i=0; i<(t-closed); i++){
                curr += ")";
            }
            ans.push_back(curr);
            return;
        }
        search(open+1, closed, t, ans, curr + "(");
        search(open, closed+1, t, ans, curr + ")");
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        search(1, 0, n, ans, "(");
        return ans;
    }
};