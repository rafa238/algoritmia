//https://leetcode.com/problems/roman-to-integer/
int converToInteger(char c){
        if(c=='I'){
            return 1;
        } else if(c == 'V'){
            return 5;
        }else if(c == 'X'){
            return 10;
        }else if(c == 'L'){
            return 50;
        }else if(c == 'C'){
            return 100;
        }else if(c == 'D'){
            return 500;
        }else if(c == 'M'){
            return 1000;
        }
        return 0;
    }
    int romanToInt(string roman) {
        int answer = 0;
        for(int i=0; i<roman.size(); i++){
            int currNumber = converToInteger(roman[i]);
            if(i == roman.size()-1){
                answer += currNumber;
                break;
            }
            int nextNumber = converToInteger(roman[i+1]);
            if(currNumber >= nextNumber ){
                answer += currNumber;
            } else {
                answer -= currNumber;
            }
        }
        return answer;
    }