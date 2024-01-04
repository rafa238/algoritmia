class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int, int> freq;

        for(int num : nums) {
            freq[num]++;
        }
        int operations = 0;
        for(auto &[num, frequency] : freq) {
            if(frequency == 1) return -1;
            operations += ceil((double)frequency / (double)3);
        }

        return operations;
    }
};