#include <bits/stdc++.h>

using namespace std;

int main(){
    int tc; cin >> tc;

    while(tc--) {
        string s;
        cin >> s;
        int i = 0, remainings = 0, ordered = 0; 
        while( i < s.size()) {
            int ones = 0, zeros = 0;
            while(i < s.size() && s[i] == '0') {
                zeros++;
                i++;
            }

            while(i < s.size() && s[i] == '1') {
                ones++;
                i++;
            }

            if(ones > 0 && zeros > 0) {
                ordered++;
            } else {
                remainings++;
            }
        }
        if(ordered > 0) {
            cout << (remainings + (ordered - 1) * 2 + 1 ) << endl;
        } else {
            cout << remainings << endl;
        }
        
    }

    return 0;
}