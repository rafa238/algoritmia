//https://www.hackerrank.com/contests/cc-problemsolving-2023/challenges/sparse-arrays/problem
/*
HashMap approach:

We'll use a hashMap (Time complexity O(1)) to store the frequency of each word in stringList

Once we get the frequency, we'll make a new array to store the frequency in queries order

Complexity:

Time O(n + m) : n -> stringList size & m -> queries size
Space O(n)


*/
vector<int> matchingStrings(vector<string> stringList, vector<string> queries) {
    unordered_map<string, int> freq;
    vector<int> answer;
    for(string s : stringList){
        freq[s]++;
    }
    for(string s:queries){
        answer.push_back(freq[s]);
    }
    
    return answer;
}