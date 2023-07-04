//https://www.hackerrank.com/contests/cc-problemsolving-2023/challenges/alternating-characters
/*
Two pointer approach:
1.put one pointer j in position 0
2.put another pointer k in position 1

while j && k its different of n-1
    if s[j] == s[k]
       only move k pointer one position to the right
    else 
       move j to k positino
       move k one position to the right

Special Case:
if n == 1:
    return 0

Complexity:
Space O(1)
Time O(n): n -> string size
*/

int alternatingCharacters(string s) {
     int n = s.size();
    if(n == 1){
        return 0;
    }
    
    int j = 0, k = 1, answer = 0;
    while(j<n && k<n){
       if(s[j] == s[k]){
           answer++;
           k++;
       } else {
           j = k;
           k++;
       }
   }
    
    return answer;
}