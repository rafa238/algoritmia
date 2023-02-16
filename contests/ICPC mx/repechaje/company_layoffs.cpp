//https://codeforces.com/gym/104120/problem/C
#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
int lowerBound(vector<ll> &v, ll target){
    ll mid,  l = 0, r = v.size() - 1;
    while(l < r){
        mid = (l+r)/2;
        if(target <= v[mid]){
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    return l;
}

int main(){
    int n, m; cin>>n>>m;
    vector<ll> v(n), prefixSum(n);
    
    for( int i=0; i<n; i++){
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    prefixSum[0] = v[0];
    for( int i=1; i<n; i++){
        prefixSum[i] = prefixSum[i - 1] + v[i];
    }
    ll q, i, len, ans;
    while(m--){
        cin>>q;
        if(q > v[n-1]) {
            cout<< prefixSum[n-1] << endl;
            continue;
        }
        i = lowerBound(v, q);
        len = v.size() - i;
        ans = len*q;
        if (len != n)
            ans += prefixSum[i-1];
        //cout<<i<<" "<<len<< endl;
        //cout<<"answer: "<<ans<<endl;
        cout << ans << endl;
    }
    return 0;
}