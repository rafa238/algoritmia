#include<bits/stdc++.h>

using namespace std;

int main(){
    int n; cin>>n;
    vector<int> v(n), vn;
    for(int i=0; i<n; i++){
        cin>>v[i];
    }
    for(int i=0; i<n-1; i++){
        vn.push_back(v[i]);
        if(abs(v[i] - v[i+1]) == 1) continue;
        if(v[i]>v[i+1]){
            for(int j = v[i]-1; j>v[i+1]; j--){
                vn.push_back(j);
            }
        } else if(v[i]<v[i+1]){
            for(int j = v[i]+1; j<v[i+1]; j++){
                vn.push_back(j);
            }
        } 
    }
    vn.push_back(v[n-1]);
    for(auto elem : vn){
        cout<<elem<<" ";
    }

    return 0;
}