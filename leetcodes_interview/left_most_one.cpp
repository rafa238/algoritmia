class Solution {
public:
    /**
     * @param binaryMatrix: A binary matrix containing only elements 0 or 1.
     * @return: The index of leftmost column with at least a one.
     */
    int getLeftmostColumnWithOne(BinaryMatrix &binaryMatrix) {
        vector<int> dimensions = binaryMatrix.dimensions();
        int n = dimensions[0], m = dimensions[1];
        int answer = -1;
        int i = 0, j = m-1;
        while(i < n && j >= 0) {
            if(binaryMatrix.get(i, j) == 0) {
                i++;
            } else {
                answer = j;
                j--;
            }
        }
        return answer;
    }
};