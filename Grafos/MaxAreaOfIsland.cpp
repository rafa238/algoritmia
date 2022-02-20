//https://leetcode.com/problems/max-area-of-island/submissions/
class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxArea = 0;
        for(int i=0;i < grid.size();i++){
            for(int j=0; j<grid[i].size(); j++){
                maxArea = max(maxArea, maxAreaDFS(grid, i, j));
            }
        }
        return maxArea;
    }

    int maxAreaDFS(vector<vector<int>>& grid, int i, int j){
        if(i>=grid.size() || j>=grid[0].size() || grid[i][j] == 0){
            return 0;
        }
        grid[i][j] = 0;
        return 1 + maxAreaDFS(grid, i, j-1) + maxAreaDFS(grid, i, j+1) + maxAreaDFS(grid, i-1, j) + maxAreaDFS(grid, i+1, j);
    }
};
