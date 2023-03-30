#include <bits/stdc++.h>
//https://practice.geeksforgeeks.org/problems/rod-cutting0840/1
using namespace std;

class Solution{
  public:
    
    int solve(vector<int> &prices, int n, vector<int> &dp){
        if(n==0) return 0;
        if(dp[n] != -100) {
            return dp[n];
        }
        int ans = INT_MIN;
        for(int i=0; i<n; i++){
            int price = prices[i];
            dp[n] = max(ans, price + solve(prices, n-(i+1), dp)); 
            ans = dp[n];
        }
        return ans;
    }
    
    int cutRod(int price[], int n) {
        vector<int> prices(price, price+n);
        vector<int> dp(n+1, -100);    
        return solve(prices, n, dp);
    }
};

int main() {

    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) 
        cin >> a[i];
        
    Solution ob;

    cout << ob.cutRod(a, n) << endl;

    return 0;
}
// } Driver Code Ends