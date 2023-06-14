#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, h;
    cin>>n>>h;
    for(int i=1; i<n; i++){
        cout<<fixed<<setprecision(12)<<(double)h*(double)sqrt((double)((double)i/(double)n))<<" ";
    }
    return 0;
}