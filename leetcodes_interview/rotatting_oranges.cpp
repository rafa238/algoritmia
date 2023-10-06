class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        //node, distance
        queue<pair<int, int>> q;
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> distances(n, vector<int>(m, 0));
        int l[4] = {-1,0,1,0};   
        int p[4] = {0,1,0,-1};

        int freshOranges = 0;
        for(int i=0; i < n; i++){
            for(int j=0; j < m; j++){
                if(grid[i][j] == 1){
                    distances[i][j] = -1;
                    freshOranges++;
                }
                if(grid[i][j] == 2){
                    q.push({i, j});  
                } 
            }
        }

        int distance = 0, answer = 0, visited_fresh = 0;
        while(!q.empty()){
            int k = q.size();
            distance++;
            for(int i = 0; i<k; i++){
                auto [x, y] = q.front();
                q.pop();
                for(int j = 0; j<4; j++){
                    int row = x + l[j], col = y + p[j];
                    if(row >= 0 && row < n && col >= 0 && col < m && distances[row][col] == -1){
                        distances[row][col] = distance;
                        q.push({row, col});
                        visited_fresh++;
                        answer = max(answer, distances[row][col]);
                    }
                }
            }
        }

        return (visited_fresh == freshOranges) ? answer : -1;
    }
};