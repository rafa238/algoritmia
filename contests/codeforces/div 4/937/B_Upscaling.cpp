#include <bits/stdc++.h>

using namespace std;

void solve(int &n) {
    
    bool catSup = true;
    for(int i = 0; i<n; i++) {
        for(int j = 0; j<2; j++) {
            bool cat = catSup;
            for(int z  = 0; z < n; z++) {
                if(cat) {
                    cout << "##";
                } else {
                    cout << "..";
                }
                cat = !cat;
            }
            cout << endl;
        }
        catSup = !catSup;
    }
}

int main(){
    int tc; cin >> tc;

    while(tc--) {
        int n ; cin >> n;
        solve(n);
    }
    

    return 0;
}