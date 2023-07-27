class Solution {
public:
    /*
        [[1,2]] -> [[1,2]]
        [[1,2], [3,4]] -> [[1,2], [3,4]]
        [[1,3],[2,6],[8,10],[15,18]] -> [[1,6], [8,10], [15,18]]
    */
    /*
    1.        |----|
        |------|
    
    2.
    |-----|
        |-----|
    3.
    |-------|
    |-------|

    4.
    |--------|
       |---|
    */
    vector<vector<int>> merge(vector<vector<int>>& s) {
        vector<vector<int>> answer;
        sort(s.begin(), s.end());
        answer.push_back(s[0]);
        for(int i=1; i<s.size(); i++){
            vector<int> curr = answer.back();
            //first case of overlaping
            if(curr[0] <= s[i][0] && s[i][0] <= curr[1]){
                cout<<"first";
                answer.pop_back();
                answer.push_back({
                    min(s[i][0], curr[0]), 
                    max(s[i][1], curr[1])
                });
                //second case of overlaping
            } else if (curr[0] >= s[i][0] && curr[1] <= s[i][0]) {
                answer.pop_back();
                answer.push_back({
                    min(s[i][0], curr[0]), 
                    max(s[i][1], curr[1])
                });
            } else {
                answer.push_back(s[i]);
            }
        }
        return answer;
    }
};