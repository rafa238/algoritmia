#include <bits/stdc++.h>

using namespace std;
void solve(){
    int n, k;
    cin>>n>>k;
    vector<int> bucket(31, n);
    for(int i=0; i<n; i++){
        int number; 
        cin>>number;
        int pos = 0;
        while(number){
            if(number & 1){
                bucket[pos]--;
            }
            number = number >> 1;
            pos++;
        }
    }
    int ans = 0;
    for(int i=30; i >= 0; i--){
        if(bucket[i] <= k || bucket[i] == 0){
            k -= bucket[i];
            ans = ans | (1<<(i));
        }
    }
    cout << ans << "\n";
    
    
}
int main(){
    int tc; cin>>tc;
    while(tc--){
         solve();
    }
    return 0;
}