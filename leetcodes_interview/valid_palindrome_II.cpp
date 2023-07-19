//https://leetcode.com/problems/valid-palindrome-ii/
class Solution {
public:
    
bool recursiveCall(string &s, int l, int r, int tries){
  if(l >= r){
    return true;
  }
  bool answer = false;
  if(s[l] == s[r]){
  	  answer = recursiveCall(s, l+1, r-1, tries);
  } else if(tries == 0){
    	return false;
  } else {
    	answer = recursiveCall(s, l+1, r, tries-1);
  	  answer = answer || recursiveCall(s, l, r-1, tries-1);
  }
  return answer;
}

bool validPalindrome(string s){
  int l = 0, r = s.size()-1;
  return recursiveCall(s, l, r, 1);
}
  
};