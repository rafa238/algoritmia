#include<bits/stdc++.h>

using namespace std;

int main(){
    int tc; cin >> tc;
    while(tc--) {
        int n, k; cin >> n >> k;

        int golden_taken = 0, people_helped = 0;
        
        for(int i = 0; i<n; i++){
            int ai; cin >> ai;
            if (ai >= k) {
                golden_taken += ai;
            } else if (ai == 0 && golden_taken > 0) {
                golden_taken--;
                people_helped++;
            }
        }
        cout << people_helped << endl;
    }

    return 0;
}