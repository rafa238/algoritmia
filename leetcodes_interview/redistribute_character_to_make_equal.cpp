class Solution {
public:
    bool makeEqual(vector<string>& words) {
        unordered_map<char, int> freq;
        for (string s : words) {
            for (char c : s) {
                freq[c]++;
            }
        }
        
        for (const auto &[c, num] : freq) {
            if (num % words.size() != 0) return false;
        }
        return true;
    }
};