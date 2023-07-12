//https://leetcode.com/problems/min-stack/
class MinStack {
public:
    stack<int> s, miniums;
    MinStack() {}
    
    void push(int val) {
        if(s.empty() && miniums.empty()){
            miniums.push(val);    
        } else if(miniums.top() >= val){
            miniums.push(val);
        }
        s.push(val);
    }
    
    void pop() {
        if(miniums.top() == s.top()){
            miniums.pop();
        }
        s.pop();
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return miniums.top();
    }
};