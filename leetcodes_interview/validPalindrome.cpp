class Solution {
public:
    bool isAlphanumeric(char character){
        //Number or alphabet character
        return ('0' <= character && character <= '9') ||
                ('a'<= character && character <= 'z');
    }

    string convertString(string s){
        string newString = "";
        for(int i=0; i<s.size(); i++){
            char aux = tolower(s[i]);
            if(isAlphanumeric(aux)){
                newString += aux;
            }
        }
        return newString;
    }



    bool isPalindrome(string s) {
        string convertedString = convertString(s);
        int i = 0, j = convertedString.size() - 1;
        cout<<convertedString;
        bool answer = true;
        while(i<=j){
            if(convertedString[i] != convertedString[j]){
                answer = false;
                break;
            }
            i++;
            j--;
        }
        return answer;
    }
};