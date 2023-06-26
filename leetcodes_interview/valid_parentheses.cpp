class Solution {
public:
    bool checkBracket(stack<char> &stack, char current){
        bool ok = false;
        if(!stack.empty() && stack.top() == current){
            stack.pop();
            ok = true;
        } 
        return ok;
    }


    bool isValid(string s) {
        stack<char> stack;
        bool answer = false;
        for(int i=0; i<s.size(); i++){
            if(s[i] == '('){
                stack.push(')');
            } else if(s[i] == '['){
                stack.push(']');
            } else if(s[i] == '{'){
                stack.push('}');
            } else{
                bool ok = checkBracket(stack, s[i]);
                if(!ok)
                    return false;
            }
         }
        if(stack.empty()){
            answer = true;
        }
        return answer;
    }