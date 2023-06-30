//https://www.hackerrank.com/contests/cc-problemsolving-2023/challenges/maximum-element/problemhttps://www.hackerrank.com/contests/cc-problemsolving-2023/challenges/maximum-element/problem
vector<int> getMax(vector<string> operations) {
    stack<int> stack, maxiums;
    vector<int> answer;
    int op;
    for(auto s : operations){
       if(s.size() != 1){
           int num;
           sscanf(s.c_str(),"%d %d", &op, &num);
           if(stack.empty() && maxiums.empty()){
               stack.push(num);
               maxiums.push(num);
           } else if (num >= maxiums.top()){
               maxiums.push(num);
               stack.push(num);
           } else {
               stack.push(num);
           }
           
       } else {
           if(stack.empty() || maxiums.empty()) continue;
           if(s=="2"){
               if(stack.top() == maxiums.top()){
                   maxiums.pop();
               }
               stack.pop();
           } else if(s == "3"){
               answer.push_back(maxiums.top());
           }
       } 
    }
    
    return answer;
}