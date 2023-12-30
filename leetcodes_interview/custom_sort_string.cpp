class Solution {
public:
    string customSortString(string order, string s) {
        unordered_map<char, int> freq;
        string answer = "";
        for (char c : s) {
            if(freq.count(c) == 0) {
                freq[c] = 0;
            }
            freq[c]++;
        }

        for (char c : order) {
            if(freq.count(c) == 0) continue;
            for (int i = 0; i < freq[c]; i++) {
                answer += c;
            }
            freq[c] = 0;
        }
        //add remaninings
        for(const auto &[c, fre] : freq) {
            if(fre == 0) continue;
            for (int i = 0; i < fre; i++) {
                answer += c;
            }
        }

        return answer;
    }
};