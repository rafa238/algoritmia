//Cumulative sum query
//https://www.spoj.com/problems/CSUMQ/

#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n,q,a;
    cin>>n;
    vector<int> prefixSum(n+1);
    prefixSum[0] = 0;
    for(int i=1; i<=n; i++){
        cin>>a;
        prefixSum[i] = a + prefixSum[i-1];
    }
    cin>>q;
    int i,j;

    while(q--){
        cin>>i>>j;
        cout<<prefixSum[j+1] - prefixSum[i]<<endl;
    }

    return 0;
}