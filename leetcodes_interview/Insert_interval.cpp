class Solution {
public:

    /*
        |   | 
           |   |

        |   |
            |   |
        
            |    | 
        |   | 

            |    |
        |      |
    */
    void pushRemainings(vector<vector<int>>& intervals, int pos, vector<vector<int>>& answer){
        for(int i=pos; i<intervals.size(); i++){
            answer.push_back(intervals[i]);
        }
    }

    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
         vector<vector<int>> ans;
        for(int i=0; i<intervals.size(); i++){
            if(newInterval[1] < intervals[i][0]){
                ans.push_back(newInterval);
                pushRemainings(intervals, i, ans);
                return ans;
            } else if(intervals[i][1] < newInterval[0]){
                ans.push_back(intervals[i]);
            } else {
                newInterval = {min(intervals[i][0], newInterval[0]), max(intervals[i][1], newInterval[1])};
            }
        }
        ans.push_back(newInterval);

        return ans;
    }
};
