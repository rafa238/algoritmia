#include<bits/stdc++.h>
using namespace std;

int main(){
    int n; cin>>n;
    vector<int> numbers(n);
    for(int i=0; i<n; i++){
        cin>>numbers[i];
    }
    int ans = 0;
    for(int i=1; i<=n; i++){
        if(i==numbers[i-1]) ans++;
    }
    cout<<ans<<endl;
    return 0;
}