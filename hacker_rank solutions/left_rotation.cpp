//https://www.hackerrank.com/contests/cc-problemsolving-2023/challenges/array-left-rotation
vector<int> rotateLeft(int d, vector<int> arr) {
    int n = arr.size();
    vector<int> answer(n,-1);
    for(int i=0; i<n; i++){
        int newPosition = (i-d+n)%n;
        answer[newPosition] = arr[i];
    }
    return answer;
}
