class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size(), columns = matrix[0].size();
        int top = 0, bottom = rows-1;
        int m;
        while(top <= bottom){
            m = (top + bottom) / 2;
            if(target < matrix[m][0]){
                bottom = m - 1;
            } else if(target > matrix[m][columns-1]){
                top = m + 1;
            } else {
                //we found the correct row
                break;
            }
        }
        cout << m;
        //once we find out the correct row
        //lets make a bs over the row
        int l = 0, r = columns-1, t;
        while(l <= r){
            t = (l+r)/2;
            if(matrix[m][t] == target){
                return true;
            } else if(matrix[m][t] > target){
                r = t - 1;
            } else {
                l = t + 1;
            }
        }

        return false;
    }
};
