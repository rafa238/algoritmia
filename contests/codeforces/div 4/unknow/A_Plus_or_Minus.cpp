#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int tc, a, b, c;
    cin>>tc;
    while(tc--){
        cin>>a>>b>>c;
        if(a+b == c){
            cout<<"+";
        } else {
            cout<<"-";
        }
        cout<<endl;
    }
    return 0;
}