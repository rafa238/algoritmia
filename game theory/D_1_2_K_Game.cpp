#include<bits/stdc++.h>
//https://codeforces.com/problemset/problem/1194/D
using namespace std;
typedef long long int ll;
int main(){
    int tc; cin>>tc;
    ll n, k;
    while(tc--){
        cin>>n>>k;
        
        ll cas = n % k;
        if(cas == 0){
            ll ans = n / k;
            if(ans % 2 == 0){
                cout<<"Bob";
            } else {
                cout<<"Alice";
            }
        } else {
            if((cas+1) % 2 == 0){
                cout<<"Bob";
            } else {
                cout<<"Alice";
            }
        }
        cout<<endl;
    }
}