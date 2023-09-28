#include <bits/stdc++.h>

using namespace std;

int main(){
    int tc;
    cin>>tc;
    while(tc--){
        int n, x; cin>>n>>x;
        bool ans = false;
        for(int i=0; i<n; i++){
            int elem; cin>>elem;
            if(elem == x){
                ans  = true;
            }
        }
        if(!ans) cout<<"NO\n";
        else cout<<"YES\n";
    }
    return 0;
}