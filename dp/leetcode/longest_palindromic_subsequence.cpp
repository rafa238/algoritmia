//https://leetcode.com/problems/longest-palindromic-substring/description/
class Solution {
public:
    string longestPalindrome(string s) {
        int L = 0, R = 0, ansSize = 0, n = s.size();
        //odd lenght
        for(int i=1; i<n; i++){
            int currSize = 1;
            for(int j=i+1, k=i-1; j<n && k>=0; j++, k--){
                if(s[k] != s[j]) break;
                currSize+=2;
                if(currSize >= ansSize){
                    L = k;
                    R = j;
                    ansSize = currSize;
                }
            }
        }
        //even lenght
        for(int i=0; i<n; i++){
            int currSize = 0;
            for(int j = i + 1, k = i; j<n && k>=0; j++, k--){
                if(s[j] != s[k]) break;
                currSize += 2;
                if(currSize > ansSize){
                    L = k;
                    R = j;
                    ansSize = currSize;
                }
            }
        }
        if(L == 0 && R == 0){
            return s.substr(L, R+1);
        }
        cout<<L<<R;
        return s.substr(L, ansSize);
    }
};