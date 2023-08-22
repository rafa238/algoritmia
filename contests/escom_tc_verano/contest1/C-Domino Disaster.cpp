#include <bits/stdc++.h>
#define fastIO(); ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
typedef long long ll;
 
int main(){
    fastIO();
    int t; 
    cin >> t; 
    while(t--){
        int n; cin>>n;
        vector<char> ans;
        for(int i=0; i<n; i++){
            char c; cin>>c;
            if(c == 'L'){
                ans.push_back('L');
            } else if(c == 'R'){
                ans.push_back('R');
            } else if(c == 'U'){
                ans.push_back('D');
            } else if(c=='D'){
                ans.push_back('U');
            }
        }
 
        for (auto elem:ans){
            cout<<elem;
        }
        cout<<"\n";
    }
    return 0;
}
