#include<bits/stdc++.h>

using namespace std;

int main(){
    int tc; cin >> tc; 
    while(tc--) {
        int n; cin >> n;
        vector<int> arr(n);
        for(auto &elem : arr) {
            cin >> elem;
        }

        int ans = INT_MIN;
        for(int i = 0; i<n; i++) {
            int currProduct = 1;
            for(int j = 0; j < n; j++) {
                if(j == i) {
                    currProduct *= (arr[j] + 1);
                } else {
                    currProduct *= arr[j];
                }
            }
            ans = max(ans, currProduct);
        }
        cout << ans << endl;
    }
    return 0;
}