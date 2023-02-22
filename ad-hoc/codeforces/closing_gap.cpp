//https://codeforces.com/contest/1615/problem/A
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ll tc, elem, maxi, mini, n; cin >> tc;
    while (tc--){
        cin>>n;
        ll sum = 0;
        for(int i=0; i < n; i++){
            cin>>elem;
            sum += elem;
        }
        maxi = ceil((double)sum / n);
        mini = sum / n;
        cout<<maxi - mini<<endl;
    }
    
    return 0;
}