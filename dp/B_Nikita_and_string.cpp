#include <bits/stdc++.h>
using namespace std;

int main(){
    string s; cin>>s;
    vector<int> as(s.size()+5, 0);
    vector<int> bs(s.size()+5, 0);
    s = 'd' + s;
    int n=s.size();
    for (int i = 1; i < n; i++) {
        if (s[i] == 'a') {
            as[i]++;
        }
        else{ 
            bs[i]++;
        }
    }
    for (int i = 1; i <= n; i++) {
        as[i] += as[i - 1];
        bs[i] += bs[i - 1];
    }
    int ans = 0;
    for (int i = 0; i <= n; i++) {
        for (int j = i; j <= n; j++) {
            int a = as[n] - as[j] + as[i];
            int b = bs[j] - bs[i];
            ans = max(a + b, ans);
        }
    }
    cout << ans;
    return 0;
}