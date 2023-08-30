class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        //save distance,  point
        vector<pair<int, int>> sorted;
        for(int i=0; i<points.size(); i++){
            vector<int> point = points[i];
            int x = point[0], y = point[1];
            int distance = x*x + y*y;
            sorted.push_back(make_pair(distance, i));
        }
        vector<vector<int>> kLowest;
        sort(sorted.begin(), sorted.end());
        for(int i=0; i<k; i++){
            cout<<sorted[i].first<<" "<<sorted[i].second<<"\n";
            kLowest.push_back(points[sorted[i].second]);
        }
        
        return kLowest;
    }
};