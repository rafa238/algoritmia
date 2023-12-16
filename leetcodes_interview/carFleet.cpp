class Solution {

public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>> cars;
        for(int i = 0; i < position.size(); i++){
            cars.push_back({position[i], speed[i]});
        }
        sort(cars.begin(), cars.end());
        reverse(cars.begin(), cars.end());
        stack<double> arrivals;
        for(int i = 0; i < cars.size();i++){
            double currArrival = (double)(target - cars[i].first) / (double)(cars[i].second);
            if(arrivals.size() >= 1 && currArrival > arrivals.top()){
                arrivals.push(currArrival);
            } else if(arrivals.size() == 0){
                arrivals.push(currArrival);
            }
        }
        
        return arrivals.size();
    }
};