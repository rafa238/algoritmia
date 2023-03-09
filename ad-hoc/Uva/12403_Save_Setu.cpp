#include <bits/stdc++.h>
//https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&category=0&problem=3834&mosmsg=Submission+received+with+ID+28283933
using namespace std;

int main(){
    int tc; cin >> tc;
    int donation, collected = 0;
    while(tc--){
        string op; cin>>op;
        if(op == "donate"){
            cin>>donation;
            collected += donation;
        } else {
            cout<<collected<<endl;
        }
    }
    return 0;
}

