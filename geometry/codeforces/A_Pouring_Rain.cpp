#include<bits/stdc++.h>

using namespace std;
const double pi=acos(-1.0);
int main(){
    double d, h, v, e, rainSpeed, volume, t;
    cin>>d>>h>>v>>e;
    rainSpeed=(pi*e*d*d)/4.0;
    volume=(pi*h*d*d)/4.0;
    if(rainSpeed<v){
        t=volume/(v-rainSpeed);
        cout<<"YES\n";
        cout<<fixed<<setprecision(12)<<t;
    }
    else{
        cout<<"NO";
    }
    return 0;
}