#include <bits/stdc++.h>
using namespace std;

int main(){
    int tc; cin >> tc;
    while(tc--) {
        int n; cin >> n;
        
        long long total_sum = 0, factor = 2*n;
        vector<int> people;
        for(int i = 0; i < n; i++) {
            int ai; cin >> ai;
            people.push_back(ai);
            total_sum += ai;
        }
        if(n == 1 || n == 2) {
            cout << -1 << endl;
            continue;
        }
        sort(people.begin(), people.end());
        int mid_value = people[double(n) / double(2)];
        long long ans = mid_value * factor - total_sum + 1;
        if (ans < 0) {
            ans = 0;
        }
        cout << ans << endl;

    }
    return 0;
}