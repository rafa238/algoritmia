class Solution {
public:
    int totalSum;
    vector<int> prefixSum, array;
    Solution(vector<int>& w) {
        totalSum = 0;
        prefixSum.resize(w.size());
        for (int i = 0; i < w.size(); i++) {
            totalSum += w[i];
            prefixSum[i] = totalSum;
            array.push_back(w[i]);   
        }
    }
    
    int pickIndex() {
        int random = rand() % totalSum + 1;
        int l = 0, r = prefixSum.size() - 1, m,  ans = prefixSum.size()-1;
        while(l<=r){
            m = (l+r)/2;
            if (prefixSum[m] >= random) {
                ans = m;
                r = m - 1;
            } else {
                l = m + 1;
            }
        }
        return ans;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */