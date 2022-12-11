//https://codeforces.com/contest/892/problem/B
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    
    ll n;
    scanf("%lld", &n);
    ll a[n+1];
    for (int i = 0; i < n; i++){
        scanf("%lld", &a[i]);
    }
 
    ll killer = n, vivo = 0;

    for (int i = n-1; i >=0; i--){
        if (i < killer) vivo++;
        killer = min(killer,i-a[i]);
    }

    printf("%d\n", vivo);

    return 0;
}

