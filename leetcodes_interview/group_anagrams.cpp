//group anagrams
vector<vector<string>> groupAnagrams(vector<string>& strs){
  unordered_map<string, vector<string>> groups;
  for(string s : strs){
    string currString = s;
    sort(s.begin(), s.end());
    if(groups.count(s) == 0){
      groups[s] = vector<string>{currString};
    } else {
      groups[s].push_back(currString);
    }
  }
  vector<vector<string>> answer;
  for(pair<string, vector<string>> item : groups){
    answer.push_back(item.second);
  }
  return answer;
}