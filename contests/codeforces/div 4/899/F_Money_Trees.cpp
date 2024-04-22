#include <bits/stdc++.h>

using namespace std;


void solve(){
    int n, max_fruits;
    cin >> n >> max_fruits;
    vector<int> fruits(n), heights(n); 
    for(auto &fruit : fruits) cin >> fruit;
    for(auto &height : heights) cin >> height;
    
    int ans = 0, fruits_taken = 0, start = 0;
    for(int end = 0; end < n; end++) {
        if(end > 0 && heights[end-1] % heights[end] != 0) {
            start = end;
            fruits_taken = 0;
        }
        fruits_taken += fruits[end];
        while(fruits_taken > max_fruits && start <= end) {
            fruits_taken -= fruits[start];
            start++;
        }
        ans = max(ans, end - start + 1); 
    }

    cout << ans << endl;
}

int main(){
    int tc; cin >> tc;
    while(tc--) {
        solve();
    }
    return 0;
}