#include<bits/stdc++.h>

using namespace std;

int main(){
    int tc; cin >> tc;
    for(int t=1; t <= tc; t++){
        int n; cin >> n;
        int cum = 0, ans = 0;
        int ansi = -1, ansj = -1;

        int leftPointer = 1;
        for(int i=2; i<=n; i++){
            int ride; cin >> ride;
            cum += ride;
            if(cum < 0){
                cum = 0;
                leftPointer = i;
            }
            if(ans <= cum){
                if(ans < cum || (cum == ans && (i - leftPointer > ansj - ansi))){
                    ansi = leftPointer;
                    ansj = i;
                }
                ans = cum;
            }
            
        }
        //cout << "Case "<<t<<": \n";
        if(ansi != -1 && ansj != -1)
            cout << "The nicest part of route "<<t<< " is between stops "<< ansi << " and "<< ansj << "\n";
        else 
            cout << "Route "<<t<<" has no nice parts" << "\n"; 
        //cout << ansi << " " << ansj << "\n";
    }
    return 0;
}