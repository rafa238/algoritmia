#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, h, goal;
    cin >> n >> h >> goal;

    for(int i=0; i<n; i++){
        int currPotion;
        cin>>currPotion;
        if( h + currPotion >= goal){
            cout << i + 1 << "\n";
            break;
        }
    }
    return 0;
}