//Cumulative sum query
//https://www.spoj.com/problems/CSUMQ/

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n,q,a;
    cin>>n;
    vector<int> arr;
    vector<int> prefixSum;

    cin>>a;
    prefixSum.push_back(a);
    for(int i=1; i<n; i++){
        cin>>a;
        arr.push_back(a);
        prefixSum[i] = a + prefixSum[i-1];
    }
    cin>>q;
    int i,j;

    while(q--){
        cin>>i>>j;
        cout<<prefixSum[j] - prefixSum[i-1]<<endl;
    }

    return 0;
}
