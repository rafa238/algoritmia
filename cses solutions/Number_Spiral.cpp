#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ll tc;
    cin>>tc;
    while(tc--){
        ll x, y;
        cin>>x>>y;
        ll position;
        ll z = max(x, y);
        if(z%2 == 0){
            if(z == x){
                position = (2*z) - y;
            } else {
                position = x;
            }
        } else {
            if(z == x){
                position = y;
            } else {
                position = (2*z) - x;
            }
        }

        ll biggestSquare = (z-1)*(z-1);
        ll answer = biggestSquare + position;
        cout<<answer<<"\n";
    }
    return 0;
}