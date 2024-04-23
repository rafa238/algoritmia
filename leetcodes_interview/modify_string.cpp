#include<bits/stdc++.h>

using namespace std;

int main(){
    string s; cin>>s;
    int n = s.size();
    string ans = "";
    map<char, int> ocurr;
    for(int i = 0; i<n; i++){
        char curr = s[i];
        if(ocurr.count(curr) == 0) {
            ans += curr;
            ocurr[curr] = i;
        } else {
            string new_ans = ans.substr(0, ocurr[curr]) + ans.substr(ocurr[curr] + 1) + curr;
            if(new_ans > ans) {
                ans = new_ans;
                ocurr[curr] = i;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
