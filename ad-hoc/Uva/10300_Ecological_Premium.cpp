#include<bits/stdc++.h>
//https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=608&page=show_problem&problem=1241
using namespace std;
typedef long long ll;

int main(){
    int tc; cin>>tc;
    while(tc--){
        int farmers; cin>>farmers;
        ll sum = 0;
        for(int i=0; i<farmers; i++){
            int space, animals, ecoFriendly;
            cin>>space>>animals>>ecoFriendly;
            sum += space*ecoFriendly;
        }
        cout<<sum<<endl;
    }
    
    return 0;
}