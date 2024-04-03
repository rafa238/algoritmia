//https://leetcode.com/problems/word-search/description/
class Solution {
public:
    vector<int> dx = {1, 0, -1, 0}, dy = {0, 1, 0, -1};

    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size(), m = board[0].size();
        bool ans = false;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                ans = ans || search(i, j, board, word, -1, -1);
            }
        }
        return ans;
    }

    bool isOutOfBounds(int x, int y, int n, int m) {
        if(x < 0 || x >= n || y < 0 || y >= m) {
            return true;
        }
        return false;
    }

    bool search(int currI, int currJ, vector<vector<char>>& board, string word, int parentI, int parentJ) {
        if(isOutOfBounds(currI, currJ, board.size(), board[0].size())) return false;
        if(word[0] != board[currI][currJ]) return false;
        if(word.size() == 1) return true;
        char currBoard = board[currI][currJ];
        board[currI][currJ] = '*';
        for(int move = 0; move < dx.size(); move++) {
            int nextI = currI + dx[move], nextJ = currJ + dy[move];
            if(search(nextI, nextJ, board, word.substr(1, word.size()-1), currI, currJ)) {
                board[currI][currJ] = currBoard;
                return true;
            }
        }
        board[currI][currJ] = currBoard;
        return false;
    }
};