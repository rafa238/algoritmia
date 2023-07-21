//https://leetcode.com/problems/reverse-integer/description/
class Solution {
public:
    int reverse(int x) { 
        long long currSum = 0;
        while(x != 0){
            int currDigit = x % 10;
            currSum = currSum*10 + currDigit;
            x /= 10;
            cout<<currSum<<" ";
        }
        if(currSum > INT_MAX || currSum < INT_MIN) return 0;
        return (int)currSum;
    }
};