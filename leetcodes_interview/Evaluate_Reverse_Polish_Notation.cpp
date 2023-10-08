class Solution {
public:
    
    int evalRPN(vector<string>& tokens) {
        stack<string> notations, operations;
        for(int i = tokens.size() - 1; i >= 0; i--){
            notations.push(tokens[i]);
        }
        while(!notations.empty()){
            string curr = notations.top();
            notations.pop();
            if(curr == "+"){
                string num1 = operations.top();
                operations.pop();
                string num2 = operations.top();
                operations.pop();
                operations.push(to_string(stoi(num1) + stoi(num2)));
            } else if(curr == "-"){
                string num1 = operations.top();
                operations.pop();
                string num2 = operations.top();
                operations.pop();
                operations.push(to_string(stoi(num2) - stoi(num1)));
            } else if(curr == "*"){
                string num1 = operations.top();
                operations.pop();
                string num2 = operations.top();
                operations.pop();
                operations.push(to_string(stoi(num1) * stoi(num2)));
            } else if(curr == "/"){
                string num1 = operations.top();
                operations.pop();
                string num2 = operations.top();
                operations.pop();
                operations.push(to_string( stoi(num2) / stoi(num1)));
            } else {
                operations.push(curr);
            }
        }

        return  stoi(operations.top());
    }
};