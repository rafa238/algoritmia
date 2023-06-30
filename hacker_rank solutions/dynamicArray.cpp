//https://www.hackerrank.com/contests/cc-problemsolving-2023/challenges/dynamic-array
vector<int> dynamicArray(int n, vector<vector<int>> queries) {
    vector<vector<int>> grid(n, vector<int>(0));
    vector<int> answer;
    int lastAnswer = 0;
    for(vector<int> q : queries){
        int type = q[0], x = q[1], y = q[2];
        
        if(type == 1){
            int idx = (x^lastAnswer)%n;
            grid[idx].push_back(y);
        } else {
            int idx = (x^lastAnswer)%n;
            int column = (y % grid[idx].size());
            lastAnswer = grid[idx][column];
            answer.push_back(lastAnswer);
        }
    }
    return answer;
}