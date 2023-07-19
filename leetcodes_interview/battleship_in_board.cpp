//https://leetcode.com/problems/battleships-in-a-board/
class Solution {
public:
    vector<int> dx = {1, 0}, dy = {0, 1};
    void explore(vector<vector<char>>& board, int i, int j){
        if(i>=board.size() || j>= board[0].size() || board[i][j] == '.'){
            return;
        }
        board[i][j] = 'V';
        for(int mov=0; mov<2; mov++){
            explore(board, i + dx[mov], j + dy[mov]);
        }
    }

    int countBattleships(vector<vector<char>>& board) {
        int answer = 0;
        for(int i=0; i<board.size();i++){
            for(int j=0; j<board[i].size(); j++){
                if(board[i][j] == 'X'){
                    explore(board, i, j);
                    answer++;
                }
            }
        }
        return answer;
    }
};