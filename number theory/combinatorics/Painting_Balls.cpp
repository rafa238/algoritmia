//https://atcoder.jp/contests/abc046/tasks/abc046_b
#include <bits/stdc++.h>

using namespace std;

int main(){
    int n,k; cin>>n>>k;
    int ans = k;
    for(int i=1; i<n; i++){
        ans *= (k-1); 
    }
    cout<<ans<<endl;
    return 0;
}