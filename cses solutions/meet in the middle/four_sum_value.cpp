#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

int N;
ll X;
unordered_map<ll,vector<pii>> mp;

int main(){
    cin>>N>>X;
    vector<ll> a(N+5);
    for(int i = 1; i <= N; i++){
        cin>>a[i];
        for(int j = 1; j < i; j++){
            ll psum = a[i] + a[j];
            if(psum >= X)   continue;
            if(mp.count(X-psum) != 0){
                for(pii P : mp[X-psum]){
                    if(P.first != j && P.second != j && P.first != i && P.second != i){
                        
                        cout<<P.first<<" "<<P.second<<" "<<j<<" "<<i<<"\n";
                        return 0;
                    }
                }
            } else mp[psum].push_back({j, i});
        }
    }
    cout<<"IMPOSSIBLE\n";
}