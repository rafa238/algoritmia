#include <bits/stdc++.h>

using namespace std;

int main(){
    int tc; cin >> tc;

    while(tc--){
        string s; cin>>s;
        if(s[0] == 'a' || s[1] == 'b' || s[2] == 'c')
            cout << "YES";
        else 
            cout << "NO";

        cout << endl;
    }

    return 0;
}