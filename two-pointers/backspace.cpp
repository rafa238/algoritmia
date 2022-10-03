#include <bits/stdc++.h>
using namespace std;

int main(){
    int Q;cin >> Q;
    while(Q--){
        string s, t;
        cin >> s;
        cin >> t;
        int p1 = s.size() - 1;
        bool ans = 1;
        for (int p2 = t.size() - 1; p2 >= 0; p2--){
            while (p1 >= 0 && s[p1] != t[p2]){
                p1 -= 2;
            }
            if (p1 < 0){
                ans = false;
                break;
            }
            p1 --;
        }
        string res = (ans)?"YES":"NO";
        cout<<res<<endl;
    }
    return 0;
}