//https://www.hackerrank.com/contests/cc-problemsolving-2023/challenges/icecream-parlor
/*
  Two sum problem:
  Save the difference (target - curr position) as a key and the index of curr position as a value
  Now we'll look forward for the element with value (target-curr).
  
  Complexity:
  
  space O(n)
  Time O(n)
*/

vector<int> icecreamParlor(int m, vector<int> arr) {
    unordered_map<int, int> diff;
    for(int i=0; i<arr.size(); i++){
        if(diff.count(arr[i]) != 0){
            vector<int> answer{diff[arr[i]]+1,i+1};
            return answer;
        }
        int current = m - arr[i];
        diff[current] = i; 
    }
    return vector<int>();
}