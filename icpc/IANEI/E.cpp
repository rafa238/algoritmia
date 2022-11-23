#include <bits/stdc++.h>
using namespace std;
typedef int ll;
int main(){
    ll in;
    scanf("%d", &in);
    while(in != 0){
        
        ll a = in%10;
        ll b = in/10;
        while(a+b >= 10){
            ll prev = a+b;
            a = prev%10;
            b = prev/10;
        }
        ll ans = a+b; 
        cout<<ans<<endl;
        scanf("%d", &in);
    }
}