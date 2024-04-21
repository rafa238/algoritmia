#include<bits/stdc++.h>

using namespace std;

void solve(){
    int n, m, k; 
    cin >> n >> m >> k;

    unordered_map<int, int> b_freq, c_freq;
    
    vector<int> a(n), b(m);
    for(int i = 0; i<n; i++) {
        cin >> a[i];
    }
    for(int i = 0; i<m; i++) {
        cin >> b[i];
        b_freq[b[i]]++;
    }

    int matches = 0;
    int ans = 0;
    //start window
    for(int i = 0; i < m; i++) {
        int curr_elem = a[i];
        c_freq[curr_elem]++;
        if(b_freq.count(curr_elem) != 0 && c_freq[curr_elem] <= b_freq[curr_elem]) {
            matches++;
        }
    }
    if(matches >= k) ans++;

    for(int i = m; i < n; i++) {
        int right = a[i], left = a[i-m];
        //decrement left side
        c_freq[left]--;
        if(b_freq.count(left) != 0 && c_freq[left] < b_freq[left]) {
            matches--;
        }

        //increement right side
        c_freq[right]++;
        if(b_freq.count(right) != 0 && c_freq[right] <= b_freq[right]) {
            matches++;
        }
        if(matches >= k) ans++;
    }

    cout << ans << "\n";
}
int main(){
    int tc;
    cin>>tc;
    while(tc--) {
        solve();
    }
    return 0;
}