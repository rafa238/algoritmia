#include<bits/stdc++.h>
// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3947
using namespace std;

int main(){
    int tc; cin>>tc;
    string action;
    int n, as, ans;
    while(tc--){
        cin>>n;
        ans = 0;
        vector<int> actions(n+1);
        for(int i=1; i<=n; i++){
            cin>>action;
            if(action=="LEFT"){
                actions[i] = -1;
                ans -= 1;
            } else if(action=="RIGHT"){
                actions[i] = 1;
                ans += 1;
            } else {
                cin>> action >> as;
                actions[i] = actions[as];
                ans += actions[i];
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}