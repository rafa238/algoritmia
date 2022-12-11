//https://codeforces.com/contest/865/problem/D
#include <bits/stdc++.h>

using namespace std;

int n;
long long sol;
priority_queue <int, vector<int>, greater<int>> q;

int main(){
    
    
    cin >> n;
    vector <int> a(n);
    for (int i = 0; i < n; ++i)
         cin >> a[i];
         
    
    for (int i = 0; i < n; ++i){
        
        if (!q.empty() && q.top() < a[i]){
            sol += a[i]-q.top();
            q.pop();
            q.push(a[i]);
        }
        
        q.push(a[i]);
    }
    
    cout << sol << "\n";
    
    return 0;
}