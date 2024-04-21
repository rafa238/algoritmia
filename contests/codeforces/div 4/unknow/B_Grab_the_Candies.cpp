#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int tc, a, n, bianca, mihai;
    cin>>tc;
    while(tc--){
        cin>>n;
        bianca = mihai = 0;
        while(n--){
            cin>>a;
            if(a%2==0){
                mihai += a;
            } else {
                bianca += a;
            }
        }
        if(mihai > bianca){
            cout<<"YES";
        } else {
            cout<<"NO";
        }
        cout<<endl;
    }
    return 0;
}