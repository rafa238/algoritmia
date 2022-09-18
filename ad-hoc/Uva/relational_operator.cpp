#include<bits/stdc++.h>
using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
        long long n, m; cin>>n>>m;
        if(n<m) cout<<"<"<<endl;
        else if(n==m) cout<<"="<<endl;
        else if(n>m) cout<<">"<<endl;
    }
}