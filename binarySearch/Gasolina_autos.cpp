#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int bs(ll G, vector<int> &autos, int N){
    int l = 0, r = N-1;
    int m;
    while(l <= r){
        m = (l+r)/2;
        if(autos[m] == G){
            return m+1;
        } else if(autos[m] < G){
            l = m + 1;
        } else if(autos[m] > G){
            r = m - 1;
        }
    }
    return m;
}

int main(){
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);
    int Q, N; cin >> Q >> N;
    vector<int> autos(N);
    ll sum=0;
    for (int i = 0; i < N; i++){
        int num; cin>>num;
        sum += num;
        autos[i] = sum;
    }
    while(Q--){
        ll G;
        cin>>G;
        int ans = bs(G, autos, N);
        cout<< ans <<" " << G - autos[ans-1]<<endl;
    }   
    return 0;
}