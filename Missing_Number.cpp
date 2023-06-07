#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, elem;
    cin>>n;
    unordered_set<int> s;
    
    for(int i=0; i<n-1; i++){
        cin>>elem;
        s.insert(elem);
    }

    for(int i=1; i<=n; i++){
        if(s.count(i) == 0){
            cout<<i<<"\n";
            break;
        }
    }

    return 0;
}