#include<bits/stdc++.h>
//https://acm.timus.ru/problem.aspx?space=1&num=1152
using namespace std;
vector<int> balconys;
vector<int> dp;
int n;

int solve(int mask){
    if(mask == (1<<n)-1) return 0;
    if(dp[mask] != -1) return dp[mask];
    int ans = INT_MAX;
    for(int i=0; i<n; i++){
        if(mask & (1 << i)) continue;
        
        int newMask = mask;
        for(int j=0; j<3; j++){
            newMask = newMask | (1<<((i+j)%n));
        }

        
        int damage = 0;
        //consideramos los nuevos mosntruos golpeados
        for(int monsters = 0; monsters < n; monsters++){
            if((newMask & (1<<monsters)) == 0){
                //sumamos el daño de los montruos no golpeados
                damage += balconys[monsters];
            }
        }
        ans = min(ans, solve(newMask) + damage);
        dp[mask] = ans;
    }
    return dp[mask];
}

int main(){
    cin>>n;
    balconys.resize(n);
    dp.resize((1<<n), -1);
    for(auto &x : balconys) cin>>x;
    cout<<solve(0)<<endl;
}
