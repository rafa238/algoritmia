#include <bits/stdc++.h>
//https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=607&page=show_problem&problem=3794
using namespace std;

int main(){
    int tc; cin >> tc;
    
    for(int i=1; i<=tc; i++){
        int l, w, h; cin >> l >> w >> h;
        cout<<"Case "<<i<<": ";
        if( l > 20 || w > 20 || h > 20){
            cout<<"bad";
        }  else {
            cout<<"good";
        }
        cout<<endl;
    }
    return 0;
}

