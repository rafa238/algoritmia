#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; cin>>n;
    vector<string> ingredients(n);
    for(int i=0; i<n; i++){
        string s; cin >> ingredients[i];
    }
    if(n>0) cout<<ingredients[0];
    return 0;
}