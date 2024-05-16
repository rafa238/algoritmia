#include<bits/stdc++.h>

using namespace std;


int main(){

    int tc;
    cin >> tc;

    while(tc--) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        set<int> up_side;
        for(int i = min(a, b); i <= max(a, b); i++) {
            up_side.insert(i);
        }

        //if and only if one (c or d) is in the up_side, it make a cross
        bool ans = (up_side.count(c) == 0 && up_side.count(d) == 0) || (up_side.count(c) == 1 && up_side.count(d) == 1);
        cout << (ans ? "NO" : "YES") << endl;
    }
    return 0;
}