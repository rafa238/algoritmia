#include<bits/stdc++.h>
using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
        int n, m; cin>>n>>m;
        n = n - (n%3);
        m = m - (m%3);
        cout<<(n*m)/9<<endl;
    }
}