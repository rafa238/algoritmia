//https://codeforces.com/contest/1789/problem/A
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int t;
    cin>>t;
    while(t--) {
        ll n,flag=0;
        cin>>n;
        vector < ll > v(n);
        for(ll i = 0 ; i < n ; i++) 
            cin>>v[i];
        for(ll i = 0 ; i <  n ; i++) {
            for(ll j = i+1 ; j < n; j++) {
                if(__gcd(v[i],v[j]) <= 2) {
                    flag = 1;
                    break;
                }
            }
        }
        if(flag == 1) 
           cout<<"Yes";
        else
           cout<<"No";
        cout<<endl;
    }
    return 0;
}