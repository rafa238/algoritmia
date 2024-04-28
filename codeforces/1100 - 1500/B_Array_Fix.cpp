#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n; cin >> n;
    vector<int> nums(n);
    for(int i = 0; i<n; i++) {
        cin >> nums[i];
    }
    bool ans = true;
    for(int j = n-2; j >= 0; j--) {
        if(nums[j] > nums[j+1] ) {
            if(nums[j] / 10 > nums[j] % 10) {
                ans = false;
                break;
            } else if(nums[j] % 10 > nums[j+1]) {
                ans = false;
                break;
            } else {
                nums[j] = nums[j] / 10;
            }
        }
    }
    cout << (ans ? "YES" : "NO") << endl;
}

int main(){
    int tc; cin >> tc;

    while(tc--) {
        solve();
    }

    return 0;
}