#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int main(){
    ll h; cin >> h;
    ll curr_heigh = -1, i = 0;
    while(curr_heigh < h){
        curr_heigh += pow(2, i);
        i++;
    }
    cout << i << endl;
    return 0;
}