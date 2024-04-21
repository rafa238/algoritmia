#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n, k; 
    cin >> n >> k;

    string s; 
    cin >> s;
    

    int i = 0, ops = 0; 
    while(i < n){
        if(s[i] == 'B') {
            i += k;
            ops++;
        } else {
            i++;
        }
    }
    cout << ops << endl;
}

int main(){
    int tc; cin >> tc;

    while(tc--) {
        solve();
    }
    return 0;
}