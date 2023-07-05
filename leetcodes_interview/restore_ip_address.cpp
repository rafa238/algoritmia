//https://leetcode.com/problems/restore-ip-addresses/
class Solution {
public:
    bool checkRange(string s){
        int num = stoi(s);
        return 0 <= num && num <= 255;
    }

    void makeComb(string s, string curr, int idx, int dots, vector<string> &ans){
        if(dots>4){
            return;
        }
        if(idx == s.size() && dots == 4){
            curr.pop_back();
            ans.push_back(curr);
            return;
        }
        if(s[idx] == '0'){
            makeComb(s, curr + "0." , idx+1, dots+1, ans);
            return;
        }
        string newCurr = "";
        for(int i=idx; i < s.size(); i++){
            newCurr +=  s[i];
            if(!checkRange(newCurr)){
                break;
            }
            makeComb(s, curr + newCurr + "." , i+1, dots+1, ans);
        }

    }

    vector<string> restoreIpAddresses(string s) {
        if(s.size() < 4){
            return {};
        }
        vector<string> answer;
        makeComb(s, "", 0, 0, answer);
        return answer;         
    }
};