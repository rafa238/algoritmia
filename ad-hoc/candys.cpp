#include <bits/stdc++.h>

using namespace std;

int main(){
    int T; cin>>T;
    for(int i=1; i<=T; i++){
        long long N, M; cin >> N >> M;
        long long dulces = 0;
        while(N--){
            int b; cin>>b;
            dulces += b;
        }
        long long ans = dulces % M;
        cout<<"Case #"<<i<<": "<< ans <<endl;
    }
    return 0;
}