#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    string s; cin>>s;
    ll n, s2 = 0;
    cin>>n;
    reverse(s.begin(), s.end());
    for(ll i=0; i<(ll)s.size(); i++){
        if(s[i] == '1'){
            s2 = s2 | (1LL<<i); 
        }
    }
    if(n<s2){
        cout<<"-1\n";
    } else {
        for(ll i=(ll)(s.size()-1); i>=0LL; i--){
            if(s[i] == '?' && ((s2 | (1LL<<i)) <= n)){
                s2 = (s2 | (1LL<<(i)));
            } 
        }
        cout<<s2<<"\n";
    }
    return 0;
}