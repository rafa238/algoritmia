#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;cin >> n;
    vector<int> number(n);
    for(int i=0; i<n; i++){
        cin>>number[i];
    }
    int k; cin>>k;

    int maxium; 
    for (int i = 0; i <= n-k; i++) { 
        maxium = number[i]; 
        for (int j = i; j < k+i; j++){ 
            maxium = max(maxium, number[j]);
        } 
        cout<<maxium<<" "; 
    }
    cout<<endl;
    return 0;
}