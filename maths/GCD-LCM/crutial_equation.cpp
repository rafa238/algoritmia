//https://www.spoj.com/problems/CEQU/
#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b){
    if(b == 0) return a;
    return gcd(b, a % b);
}

int main(){
    int tc; cin>>tc;
    for(int i=1; i<=tc; i++){
        int x,y,c;
        cin>>x>>y>>c;
        int mcd = gcd(x,y);
        int mcd2=gcd(mcd, c);
        cout<<"Case "<<i<<": ";
        if(mcd==mcd2){
            cout<<"Yes"<<"\n";
        } else {
            cout<<"No"<<"\n";
        }
    }
    return 0;
}