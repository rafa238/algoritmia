#include<bits/stdc++.h>
//https://leetcode.com/submissions/detail/922614035/
using namespace std;

int longestCommonSubsequence(string s1, string s2) {
    int p1 = s1.size();
    int p2 = s2.size();
    int dp[p1 + 1][p2 + 1];
    for (int i = 0; i <= p1; i++) {
        for (int j = 0; j <= p2; j++) {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
            else if (s1[i - 1] == s2[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
 
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    } 
    return dp[p1][p2];
}

int main(){
    string s1, s2;
    cin>>s1>>s2;
    cout<<longestCommonSubsequence(s1, s2);
    return 0;
}