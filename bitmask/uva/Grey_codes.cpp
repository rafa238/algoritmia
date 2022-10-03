#include<bits/stdc++.h>
using namespace std;
/*
    Uva 11173 - Grey Codes
*/
int main(){
    int Q; cin>>Q;
    while(Q--){
        int N,K; cin>>N>>K;
        int ans = K^(K>>1);
        cout<<ans<<endl;
    }
}