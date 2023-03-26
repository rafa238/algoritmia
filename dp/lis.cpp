#include<bits/stdc++.h>
//https://practice.geeksforgeeks.org/problems/longest-increasing-subsequence-1587115620/0
using namespace std;

class Solution
{
    public:

    int longestSubsequence(int n, int a[]){
        vector<int> A(a, a+n);
        vector<int> L(n, INT_MAX);
        for(int i=0; i<n; i++){
            int curr = A[i];
            int idx =  lower_bound(L.begin(), L.begin()+n, A[i]) - L.begin();
            L[idx] = curr;
            //cout<<idx<<" ";
        }
        int i = 0;
        for(auto elem: L){
            if(elem != INT_MAX){
                i++;
            }
        }
        return i;
    }
};

int main(){
    int t,n;
    cin>>t;
    while(t--){
        cin>>n;
        int a[n];
        
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution ob;
        cout << ob.longestSubsequence(n, a) << endl;
        //ob.longestSubsequence(n, a);
    }
}