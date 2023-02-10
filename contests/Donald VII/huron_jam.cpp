#include<bits/stdc++.h>
using namespace std;

int main(){
    int n; cin>>n;
    int ans = 0;
    vector<int> sk(n);
    for(int i=0; i<n; i++){
        cin>>sk[i];
    }

    for(int i=1; i<n; i+=2){
        ans += abs(sk[i-1] - sk[i]); 
    }
    cout<<ans<<endl;
    return 0;
}