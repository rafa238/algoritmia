#include <bits/stdc++.h>
//https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=608&page=show_problem&problem=562
using namespace std;

int main(){
    int tc; cin >> tc;
    string s, ans;
    while(tc--){
        cin>>s;
        int len = s.size();
        if(s == "4" || s=="1" || s=="78"){
            ans = "+";
        } else if(s[0] == '9' && s[len - 1] == '4'){
            ans = "*";
        } else if(s[len - 2] == '3' && s[len - 1] == '5'){
            ans = "-";
        } else{
            ans = "?";
        }
        cout<<ans<<endl;
    }
    return 0;
}