#include<bits/stdc++.h>
using namespace std;

int main(){
    string s, ans = ""; cin>>s;
    for(auto character : s){
        ans += (character == '0') ? '1' : '0';
    }
    cout<<ans<<endl;
    return 0;
}