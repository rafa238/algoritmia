#include<bits/stdc++.h>
using namespace std;

bool visitado[500];
long long int memo[500];
#define MOD 1000000007

long long int dp(long long int i){
    if(i == 1 || i==2) return 1;
    if(!visitado[i]){
        long long int mov1 = dp(i-1);
        long long int mov2 = dp(i-2);
        memo[i] = (mov1 + mov2) % MOD;
    }
    return memo[i];
} 

int dpIterativa(int f){
    memo[1] = 1;
    memo[2] = 1;
    for (int i = 3; i <= f; i++){
        memo[i] = (memo[i-1] + memo[i-2]) % MOD;
    }
    return memo[f];
    
}

int main(){
    int n; cin>>n;
    cout << dp(n);
    return 0;
} 