#include <bits/stdc++.h>
using namespace std;
#define fast_io ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

int upperBound(vector<ll> &v, ll target){
    ll mid,  l = 0, r = v.size() - 1;
    while(l < r){
        mid = (l+r)/2;
        if(target < v[mid]){
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    return l;
}


int main(){
    fast_io;
    int n, k;
    cin>>n>>k;
    long double thickness = 0;
    vector<int> t(n);
    map<int, int> days_thickness; 
    for(int i=0; i<n; i++){
        cin>>t[i];
        t[i] = -t[i];

        thickness += t[i]*0.2;
        if(thickness <= 0){ 
            thickness = 0;
        }
        days_thickness[thickness]++;
    }
    vector<int> prefix, cm;
    for(auto elem : days_thickness){
        prefix.push_back(elem.second);
        cm.push_back(elem.first);
    }
    for(int i=prefix.size()-2; i>=0; i--){
        prefix[i] += prefix[i+1]; 
    }
    
    for(int i=0; i<k; i++){
        int person; cin>>person;
        int idx = upperBound(cm, person)-1;
        if(idx >= cm.size()){
            cout<<0<<" ";
        } else {
            cout<<prefix[idx]<<" ";
        }
    }
    cout<<endl;
    return 0;
}