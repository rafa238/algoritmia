//https://leetcode.com/problems/spiral-matrix/
class Solution {

public:
    void move(int &i, int &j, int &move){
        /*
            0. right
            1. down
            2. left
            3. up
        */
        switch(move){
            case 1:
                i++;
                break;
            case 0:
                j++;
                break;
            case 3:
                i--;
                break;
            case 2:
                j--;
                break;
        }
        return;
    }

    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        vector<int> answer;
        int i = 0, j=0;
        visited[i][j] = true;
        answer.push_back(matrix[i][j]);
        
        int currMove = 0;
        for(int idx=0; idx<n*m-1; idx++){
            //keep track of the previous movement
            int previ = i, prevj = j;

            //lets make the move
            move(i, j, currMove);

            //if the new current position is out of bounds, lets go back to the previuos position
            //and update the move, in this way we can go torward
            if(i >= n || i < 0 || j >= m || j < 0 || visited[i][j]){
                //make the new movement
                currMove++;
                currMove %= 4;
                //go back and make the move in the new direction
                i = previ;
                j = prevj;
                move(i, j, currMove);
            }
            //push the current element and mark as visited
            answer.push_back(matrix[i][j]);
            visited[i][j] = true;
        }
        return answer;
    }
};