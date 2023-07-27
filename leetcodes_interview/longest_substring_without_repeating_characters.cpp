//https://leetcode.com/problems/longest-substring-without-repeating-characters/description/
class Solution {
public:
    /*  
        Edge Cases:
        "" -> 0
        "b" -> 1
        "aaa" -> 1
        "abcd" -> 4
        "abcba" -> 3
    */
    int lengthOfLongestSubstring(string s) {
        int l = 0, answer = 0;
        set<char> diferents;
        for(int r = 0; r < s.size(); r++){
            while(diferents.count(s[r]) != 0){
                diferents.erase(s[l]);
                l++;
            }
            diferents.insert(s[r]);
            answer = max(answer, (int)diferents.size());
        }
        return answer;
    }
};
