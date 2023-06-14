#include<bits/stdc++.h>

using namespace std;

int main(){
    int n; cin>>n;
    int maxX = INT_MIN, maxY = INT_MIN;
    for(int i=0; i<n; i++){
        int x, y;
        cin>>x>>y;
        if(maxX + maxY < x + y){
            maxX = x;
            maxY = y;
        }
    }
    cout<<maxX + maxY<<"\n";
    return 0;
}