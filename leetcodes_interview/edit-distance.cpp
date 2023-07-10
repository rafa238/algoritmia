//https://leetcode.com/problems/edit-distance/description/
class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size() + 1, m = word2.size() + 1;
        vector<vector<int>> grid(n, vector<int>(m, -1));
        for(int i=0; i<n; i++){
            grid[i][0] = i; 
        }
        for(int i=0; i<m; i++){
            grid[0][i] = i;
        }
        for(int i=1; i<n; i++){
            for(int j=1; j<m; j++){
                if (word1[i - 1] == word2[j - 1]) {
                    grid[i][j] = grid[i - 1][j - 1];
                } else {
                    grid[i][j] = 1 + min({grid[i - 1][j - 1], grid[i][j - 1], grid[i - 1][j]});
                }
            }
        }
        return grid[n-1][m-1];
    }
};