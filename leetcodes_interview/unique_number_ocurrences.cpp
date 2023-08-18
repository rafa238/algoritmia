class Solution {
public:
    bool uniqueOccurrences(vector<int>& numbers) {
        unordered_map<int, int> ocurrences;
        for(int i=0; i < numbers.size(); i++){
            int currentNumber = numbers[i];
            ocurrences[currentNumber]++;
        }
        unordered_set<int> uniqueOcurr;
        for(pair<int, int> elem : ocurrences){
            if(uniqueOcurr.count(elem.second) != 0){
                return false;
            } else {
                uniqueOcurr.insert(elem.second); 
            }
        }
        
        return true;
    }
};