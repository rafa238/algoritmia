#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie();

    ll n; cin>>n;
    string s = "";
    for(ll i = 0; i<n; i++){
        s += "a";
    }
    for(ll i = 2; i<n; i+=4){
        s[i] = 'b';
        if(i+1 < n){
            s[i+1] = 'b';
        }
    }
    cout<<s<<endl;
    cin.clear();
    cin.ignore();

    return 0;
}