//https://leetcode.com/submissions/detail/991294633/
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> f;
        for(int num : nums){
            f[num]++;
        }
        //store value, key
        vector<pair<int, int>> aux;
        for(pair<int, int> elem : f){
            aux.push_back({elem.second, elem.first});
        } 
        sort(aux.begin(), aux.end(), greater<>());
        vector<int> answer;
        for(int i=0; i<k; i++){
            answer.push_back(aux[i].second);
        }
	    return answer;
    }
};