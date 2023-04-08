#include<bits/stdc++.h>
//https://codeforces.com/problemset/problem/1194/D
using namespace std;
typedef long long int ll;
int main(){
    int tc; cin>>tc;
    ll n, k;
    while(tc--){
        cin>>n>>k;
        if(k%3 == 0){
            ll aux = n%(k+1);
            if(aux%3 == 0 && aux != k){
                cout<<"Bob";
            } else {
                cout<<"Alice";
            }
        } else {
            if(n%3 == 0){
                cout<<"Bob";
            } else {
                cout<<"Alice";
            }
        }
        cout<<endl;
    }
}