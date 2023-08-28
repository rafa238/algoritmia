#include <bits/stdc++.h>
using namespace std;

int main(){
    int tc; cin >> tc;
    while(tc--){
        int n; cin >> n;
        vector<int> vec(n), ones(n, 0), twos(n, 0);
        for(int i=0; i<n; i++){
            cin>>vec[i];
        }

        if(n == 1){
            cout <<0<<" ";
            continue;
        }
        if(vec[0] == 1){
            ones[0] = 1;
        } else {
            twos[0] = 1;
        }
        
        
        for(int i=1; i<n; i++){
            ones[i] = ones[i-1];
            twos[i] = twos[i-1];
            if(vec[i] == 1){
                ones[i]++;
            } else {
                twos[i]++;
            }
        }

        // cout<<"prefix \n";
        // for(int i=0; i<n; i++){
        //     cout<<ones[i]<<" ";
        // }
        // cout<<"\n";
        // for(int i=0; i<n; i++){
        //     cout<<twos[i]<<" ";
        // }
        // cout<<"\n";

        int ans = INT_MAX;
        for(int i=1; i<n; i++){
            // cout<<ones[n-1]<<" "<<ones[i-1]<< " " << twos[i-1]<<"\n";
            ans = min(ans, ones[n-1] - ones[i-1] + twos[i-1]);
            ans = min(ans, twos[n-1] - twos[i-1] + ones[i-1]);
        }
        ans = min(ans, min(twos[n-1], ones[n-1]));
        cout << ans<<" ";
    }
    return 0;
}