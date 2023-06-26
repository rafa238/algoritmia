class Solution {
public:
    map<char, string> phone;
    void combine(int pos, string current, string digits, vector<string> &ans){
        if(pos >= digits.size()){
            ans.push_back(current);
        }
        char currNumber = digits[pos];
        for(int i = 0; i < phone[currNumber].size(); i++){
            combine(pos+1, current + phone[currNumber][i], digits, ans);
        }
    }

    vector<string> letterCombinations(string digits) {
        if(digits == ""){
            return {};
        }
        phone['2'] = "abc";
        phone['3'] = "def";
        phone['4'] = "ghi";
        phone['5'] = "jkl";
        phone['6'] = "mno";
        phone['7'] = "pqrs";
        phone['8'] = "tuv";
        phone['9'] = "wxyz";
        vector<string> ans;
        
        combine(0, "", digits, ans);
        return ans;
    }
};