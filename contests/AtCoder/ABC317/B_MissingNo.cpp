#include <bits/stdc++.h>

using namespace std;

int main(){
    int n; cin>>n;
    int minium = INT_MAX, maxium = INT_MIN, sum = 0;
    for(int i=0; i<n; i++){
        int elem; cin>>elem;
        minium = min(elem, minium);
        maxium = max(elem, maxium);
        sum += elem;
    }

    int gaussUpper = maxium*(maxium+1)/2;
    int gaussLower = (minium-1)*(minium)/2;
    int gaussRange = gaussUpper - gaussLower;
    cout<<gaussRange - sum;
    return 0;
}