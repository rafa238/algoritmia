#include <bits/stdc++.h>

using namespace std;

int main(){
    int N; cin>>N;
    for(int i=1; i<=N; i++){
        long long L, R; cin>> L >> R;
        long long sub = min(L, R);
        long long ans = (sub*(sub+1))/2;
        cout<<"Case #"<<i<<": "<<ans<<endl;
    }
    return 0;
}

