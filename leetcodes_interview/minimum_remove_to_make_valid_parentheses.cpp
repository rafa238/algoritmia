class Solution {
public:
    string minRemoveToMakeValid(string s) {
        //parenthesis index position
        vector<int> opens, closes;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '('){
                opens.push_back(i);
            } else if(s[i] == ')'){
                if(opens.empty()){
                    closes.push_back(i);
                    continue;
                }
                opens.pop_back();
            }
        }
        int x = 0, y = 0;
        string answer = "";
        for(int i = 0; i<s.size(); i++){
            if(opens.size() > x && i == opens[x]) {
                x++;
                continue;
            } else if(closes.size() > y && i == closes[y]) {
                y++;
                continue;
            }
            answer += s[i];
        }
        


        return answer;
    }
};