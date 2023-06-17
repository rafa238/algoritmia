#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

vector<ll> fst, snd;
unordered_map<ll, int, custom_hash> m;
ll n, ans, target, elem;

int main(){
    cin>>n>>target;
    ans = 0;
    int n1 = n/2, 
    n2 = n - n1;
    for(int i=0; i<n1; i++){
        cin>>elem;
        fst.push_back(elem);
    }
    for(int i=0; i<n2; i++){
        cin>>elem;
        snd.push_back(elem);
    }

    for(int i=0; i<(1<<(n1)); i++){
        ll sum = 0;
        for(int j = i, y=0; j > 0; j >>= 1, y++){
            if(j&1){
                sum += fst[y];
            }
        }
        m[sum]++;
    }

    for(int i=0; i<(1<<n2); i++){
        ll sum = 0;
        for(int j = i, y=0; j > 0; j >>= 1, y++){
            if(j&1){
                sum += snd[y];
            }
        }
        if(m.count(target-sum)){
            ans+=m[target-sum];
        }
    }
    cout<<ans<<"\n";
    return 0;
}