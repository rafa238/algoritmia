class Solution
{
public:
    int longestPalindrome(string s)
    {
        unordered_map<char, int> freq;
        for (auto elem : s)
        {
            freq[elem]++;
        }
        bool hasOdd = false;
        int answer = 0;
        for (auto elem : freq)
        {
            if (elem.second % 2 == 0)
            {
                answer += elem.second;
            }
            else
            {
                answer += elem.second - 1;
                hasOdd = true;
            }
        }
        if (hasOdd)
            answer++;
        return answer;
    }
};