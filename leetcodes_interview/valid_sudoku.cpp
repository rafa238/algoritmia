//https://leetcode.com/problems/valid-sudoku/description/
/*
    1. make two hash maps, one for rows and the second one for columns
    2. traverse by sectors
    3. keep a set for every sector and check that every element is different
*/
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        
        unordered_map<char, unordered_set<int>> rows, columns;
        //traverse by sector
        for(int sectorx = 0; sectorx < 3; sectorx++){
            for(int sectory = 0; sectory < 3; sectory++){
                //traverse by element of every sector
                int initialColumn = 3*sectory, 
                    initialRow = 3*sectorx;
                unordered_set<int> differentSector;
                for(int i = initialRow; i < initialRow + 3; i++){
                    for(int j = initialColumn; j < initialColumn + 3; j++){
                        char curr = board[i][j];
                        if(curr == '.') continue;
                        if(rows[curr].count(i) != 0 
                            || columns[curr].count(j) != 0
                            || differentSector.count(curr) != 0){
                            return false;
                        }
                        rows[curr].insert(i);
                        columns[curr].insert(j);
                        differentSector.insert(curr);
                    }
                }
            }
        }
        return true;
    }
};