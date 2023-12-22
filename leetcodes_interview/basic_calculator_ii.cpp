class Solution {
public:
    int calculate(string s) {
        int num = 0;
        char op = '+';
        stack<int> nums;
        for(char c : s){
            if(c == ' ') continue;
            if( c >= '0' && c <= '9'){
                num = num*10 + (c - '0');
            }
            else{
                if(op == '+'){
                    nums.push(num);
                } else if(op == '-'){
                    nums.push(num*-1);
                } else if(op == '*'){
                    int top = nums.top();
                    nums.pop();
                    nums.push(num*top);
                } else if(op == '/'){
                    int top = nums.top();
                    nums.pop();
                    nums.push(top / num);
                }
                num = 0;
                op = c;
            }
        }
        cout << num;
        if(op == '+'){
            nums.push(num);
        } else if(op == '-'){
            nums.push(num*-1);
        } else if(op == '*'){
            int top = nums.top();
            nums.pop();
            nums.push(num*top);
        } else if(op == '/'){
            int top = nums.top();
            nums.pop();
            nums.push(top / num);
        }
        int answer = 0;
        while(!nums.empty()){
            answer += nums.top();
            nums.pop();
        }

        return answer;
    }
};