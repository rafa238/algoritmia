#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

int main(){
    int n; cin>>n;
    vi elems(n);
    vi lis(n, 1);
    for(int i=0; i<n; i++){
        cin >> elems[i];
    }

    for(int i = elems.size()-1; i >= 0; i--){
        for(int j=i+1; j<elems.size(); j++){
            if(elems[i]<elems[j]){
                lis[i] = max(lis[i], 1 + lis[j]);
            }
        }
    }
    int ans = INT_MIN;
    for( auto elem: lis){
        //cout<<elem<<" ";
        ans = max(ans, elem);
    }
    cout<<ans<<endl;
    return 0;
}