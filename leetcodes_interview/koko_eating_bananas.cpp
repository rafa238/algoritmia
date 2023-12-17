class Solution {
public:
    long long max_array(vector<int> &piles){
        long long maximum = INT_MIN;
        for(int elem : piles){
            maximum = max(maximum, (long long)elem);
        }
        return maximum;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        long long l = 1, r = max_array(piles), answer = r;
        while(l <= r){
            long long k = (l+r)/2;
            long long spendHours = 0;
            for(int i = 0; i < piles.size(); i++){
                spendHours += ceil((double)piles[i]/(double)k);
            }
            if(spendHours > h){
                l = k+1;
            } else {
                answer = min(answer, k);
                r = k-1;
            }
        }
        return answer;
    }
};