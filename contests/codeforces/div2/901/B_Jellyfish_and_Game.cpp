#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(){
    int tc; cin>>tc;
    while(tc--){
        int n, m;
        ll k;

        cin>>n>>m>>k;
        

        ll jelyMaxium = INT_MIN, gellyMaxium = INT_MIN;
        ll jelyMinium = INT_MAX, gellyMinium = INT_MAX;
        ll jelySum = 0, gellySum = 0;
        for(int i=0; i<n; i++){
            ll elem; cin>>elem;
            jelyMaxium = max(jelyMaxium, elem);
            jelyMinium = min(jelyMinium, elem);
            jelySum += elem;
        }

        for(int i=0; i<m; i++){
            ll elem; cin>>elem;
            gellyMaxium = max(gellyMaxium, elem);
            gellyMinium = min(gellyMinium, elem);
            gellySum += elem;
        }

        ll overAllMinium = min(gellyMinium, jelyMinium), overAllMaxium = max(jelyMaxium, gellyMaxium);
        if(jelyMinium > gellyMaxium){
            if(k == 1){
                cout << jelySum << "\n";
                continue;
            }
        } else {
            jelySum -=  jelyMinium;
            jelySum += gellyMaxium;
            gellySum -= gellyMaxium;
            gellySum += jelyMinium;
        }
        k--;
        if(k % 2 == 1){
            jelySum -= overAllMaxium;
            jelySum += overAllMinium;
            cout << jelySum << "\n";
        } else {
            cout << jelySum << "\n";
        }
    }
    return 0;
}