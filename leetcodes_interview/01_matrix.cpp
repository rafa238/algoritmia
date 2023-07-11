//https://leetcode.com/problems/01-matrix/
class Solution {
public:
    vector<int> x = {1, 0, -1, 0};
    vector<int> y = {0, -1, 0, 1};

    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        vector<vector<int>> answer(n, vector<int>(m, INT_MAX));
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        queue<pair<pair<int, int>, int>> q;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(mat[i][j] == 0){
                    q.push({{i, j}, 0});
                    visited[i][j] = true;
                }
            }
        }
        while(!q.empty()){
            pair<pair<int, int>, int> curr = q.front();
            pair<int, int> cords = curr.first;
            int distance = curr.second;
            q.pop();
            answer[cords.first][cords.second] = min(distance, answer[cords.first][cords.second]);
            visited[cords.first][cords.second] = true;
            for(int i=0; i<4; i++){
                int newI = cords.first + x[i], newJ = cords.second + y[i];
                if(newI<0 || newI>=n || newJ < 0 || newJ>=m)
                    continue;
                if(visited[newI][newJ] == false)
                    q.push({{newI, newJ}, distance + 1});
            }
        }
        return answer;
    }
};