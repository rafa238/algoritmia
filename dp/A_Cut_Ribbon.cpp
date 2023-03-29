#include <bits/stdc++.h>
//https://codeforces.com/contest/189/problem/A
using namespace std;

vector<int> dp;
int n, a, b, c;

int solve(int currLength){
    if(currLength == 0){
        return 0;
    }
    if(currLength < 0){
        return INT_MIN;
    }
    if(dp[currLength] != -1){
        return dp[currLength];
    }
    
    dp[currLength] = 1 + max(solve(currLength - a), max(solve(currLength - b), solve(currLength - c)));
    
    return dp[currLength];
}

int main(){
    cin>>n>>a>>b>>c;
    dp.resize(n+1, -1);
    cout<<solve(n);
    return 0;
}