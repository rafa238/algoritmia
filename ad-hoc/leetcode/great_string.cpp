/*
* https://leetcode.com/problems/make-the-string-great/
*/

class Solution {
public:
    string makeGood(string s) {
        vector<char> chars;
        string answer="";
        for(int i=0; i<s.size(); i++){
            if(chars.size()==0){
                chars.push_back(s[i]);
            } else if(abs(chars[chars.size()-1]-s[i])==32){
                chars.pop_back();
            } else {
                chars.push_back(s[i]);
            }
        }
        for(auto c:chars){
            answer+=c;
        }
        return answer;
    }
};