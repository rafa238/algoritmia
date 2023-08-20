class Solution {
public:
    string intToRoman(int num) {
        unordered_map<int, string> romanSimbols = {
            {0, ""},
            {1, "I"},
            {5, "V"},
            {10, "X"},
            {50, "L"},
            {100, "C"},
            {500, "D"},
            {1000, "M"}
        };
        int dezen = 1;
        string answer = "";
        while(num != 0){
            int currDigit = (num % 10);
            if(currDigit == 4 || currDigit == 9){
                //especial case
                answer = (romanSimbols[dezen] + romanSimbols[currDigit*dezen + dezen]) + answer;
            } else {
                //another number
                string currNumber = "";
                if(currDigit >= 5 ){
                    currNumber = romanSimbols[5*dezen];
                    currDigit -= 5;  
                }
                while(currDigit*dezen != 0){
                    currNumber = currNumber + romanSimbols[dezen];
                    currDigit--;
                }
                answer = currNumber + answer;
            }
            dezen *=10;
            num /= 10;
        }
        return answer;
    }
};