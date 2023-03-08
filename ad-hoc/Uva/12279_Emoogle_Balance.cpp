#include<bits/stdc++.h>
using namespace std;

int main(){
    int tc;
    int i=0;
    while(cin>>tc, tc != 0){
        
        int n, ans = 0;
        for(int i=0; i<tc; i++){
            cin>>n;
            if(n==0) ans--;
            else ans++;
        }
        cout<<"Case "<<++i<<": ";
        cout << ans << endl;
    }
    return 0;
}