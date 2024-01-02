class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int k = s1.size(), n = s2.size();
        unordered_map<char, int> bucket;
        for (char c : s1) {
            if(bucket.count(c) == 0){
                bucket[c] = 0;
            }
            bucket[c]++;
        }
        int missing = bucket.size();
        int l = 0, r = -1;
        while(r < n) {
            if (r - l + 1 == k) {
                
                if (bucket.count(s2[l]) != 0)
                {
                    if(bucket[s2[l]] == 0)
                        missing++;
                    bucket[s2[l]]++;
                }
                r++;
                l++;
                if (bucket.count(s2[r]) !=0)
                {
                    bucket[s2[r]]--;
                    if(bucket[s2[r]] == 0) {
                        missing--;
                    }
                }
            } else {
                r++;
                if (bucket.count(s2[r]) != 0)
                {
                    bucket[s2[r]]--;
                    if(bucket[s2[r]] == 0) {
                        missing--;
                    }
                }
                
            }
            if(missing == 0)
                return true;
        }

        return false;
    }
};