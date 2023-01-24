//11547 - Automatic Answer
//https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=607&page=show_problem&problem=2542
#include <bits/stdc++.h>
#define fstIO ios_base::sync_with_stdio(0); cin.tie(NULL);
using namespace std;

int main(){
    fstIO;
    int tc, n, ans; 
    cin >> tc;
    while(tc--){
        cin >> n;
        ans = (63 * n + 7492) * 5 - 498;
        
        ans /= 10;
        cout << abs(ans  % 10) << endl;
    }
    return 0;
}