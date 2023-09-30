#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int main(){
    ll tc; cin>>tc;

    while(tc--){
        ll maxium, initial, tools;
        cin>>maxium>>initial>>tools;
        ll ans = (initial - 1);
        for(int i=0; i<tools; i++){
            ll curr; cin>>curr;
            ans += min( 1LL + curr, maxium);
            if(i < tools - 1){
                ans--;
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}