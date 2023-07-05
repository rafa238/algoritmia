//https://www.hackerrank.com/contests/cc-problemsolving-2023/challenges/recursive-digit-sum
/*
Brute force:
    1.superdigit will make the conversion of n to n*k, in this way we avoid make concatenation
    2.Execute SumString that will make the recursive procedure of sum every 
    number in the string and passing to sumString   again
    3. Base case will exectute when we already have a single number
    
    Complexity:
    Time: O(n*k) n is the leght and k is the number of times we recall the sumString function
    Space: O(1)
*/
typedef long long ll;

int converCharToInt(char c){
    return c - '0';
}

int sumString(string n){
    if(n.size() == 1){
        return converCharToInt(n[0]);
    }
    ll sum = 0;
    for(char c : n){
        ll currNumber = converCharToInt(c);
        sum += currNumber;
    }
    return sumString(to_string(sum));
}

int superDigit(string n, int k) {
    ll sum = 0;
    for(char c:n){
        int currNumber = converCharToInt(c);
        sum += currNumber;
    }
    sum *= k;
    return sumString(to_string(sum));
}