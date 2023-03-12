#include<bits/stdc++.h>
//https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2899
using namespace std;

int main(){
    int tc; cin>>tc;
    int n, crature, ans, i=0;
    while(tc--){
        ans = INT_MIN;
        cin>>n;
        for(int j=0; j<n; j++){
            cin>>crature;
            ans = max(ans, crature);
        }
        cout<<"Case "<< ++i <<": "<< ans <<endl;
    }
    return 0;
}