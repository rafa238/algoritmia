//Uva Judge: 11498 - Division of Nlogonia
//https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=607&page=show_problem&problem=2493
#include <bits/stdc++.h>
#define fstIO ios_base::sync_with_stdio(0); cin.tie(NULL);
using namespace std;

int main(){
    fstIO;
    int k;
    while( cin>>k, k !=0){
        int n, m, x, y; cin >> n >> m;
        for(int i=0; i<k; i++){
            cin >> x >> y;
            if(x == n || y == m){
                cout << "divisa" << endl;
            } else if(x > n && y > m){
                cout << "NE" << endl;
            } else if (x > n && y < m ){
                cout << "SE" << endl;
            } else if (x < n && y < m ){
                cout << "SO" << endl;
            } else if (x < n && y > m ){
                cout << "NO" << endl;
            }
        }
    }
    return 0;
}