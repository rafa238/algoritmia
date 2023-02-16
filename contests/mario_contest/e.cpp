//dp, pero se desborda UnU

#include <bits/stdc++.h>
using namespace std;

int dp[100000];

int sol(int a, int *arr){
    //cout<<a<<": "<<dp[a]<<" ---  ";
    //cout<<a<<" ";
    if(dp[a] != 0) return dp[a];
    if(a == 1) return 1;
    
    int cont = 1;
    if(a%2 != 0){
        cont += sol((a*3)+1, arr);
    } else {
        cont += sol(a /= 2, arr);
    }
    dp[a] = cont - 1;
    return cont;
}

int main(){
    int N, M; cin>>N>>M; 
    memset(dp, 0, 1000);
    int ans = INT_MIN;
    while(N<=M){
        ans = max(sol(M, dp), ans);
        //cout<<M<<" ";
        M--;
    }
    cout<<ans;
    return 0;
}