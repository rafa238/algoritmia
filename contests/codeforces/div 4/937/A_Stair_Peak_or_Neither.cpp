#include <bits/stdc++.h>

using namespace std;

void solve() {
    int a, b, c;
    cin >> a >> b >> c;
    if(a < b && b < c) {
        cout << "STAIR";
    } else if( a < b && b > c) {
        cout << "PEAK";
    } else {
        cout << "NONE";
    }
    cout << endl;
}

int main(){
    int tc; cin >> tc;
    while(tc--) {
        solve();
    }

    return 0;
}