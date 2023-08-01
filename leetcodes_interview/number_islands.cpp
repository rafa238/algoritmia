//https://leetcode.com/problems/number-of-islands/description/
class Solution {
public:
    vector<int> dx = {1, 0, -1, 0}, dy = {0, 1, 0, -1};
    void explore(vector<vector<char>>& grid, int i, int j){
        if(i<0 || i >= grid.size() || j<0 || j>= grid[0].size()){
            return;
        }
        if(grid[i][j] != '1'){
            return;
        }
        grid[i][j] = '0';
        for(int idx=0; idx<4; idx++){
            explore(grid, i + dy[idx], j + dx[idx]);
        }

    }

    int numIslands(vector<vector<char>>& grid) {
        int islands = 0;
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[i].size(); j++){
                if(grid[i][j] == '1'){
                    islands++;
                    explore(grid, i, j);
                }
            }
        }
        return islands;
    }
};