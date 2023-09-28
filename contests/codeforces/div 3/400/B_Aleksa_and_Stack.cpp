#include <bits/stdc++.h>

using namespace std;

int main(){
    int tc;
    cin>>tc;
    while(tc--){
        int n; cin>>n;
        cout<<7<<" " <<11<<" ";
        int fst = 7, snd = 11, cont = 2;
        for(int i = snd+1; i>1; i++){
            if(cont == n){
                break;
            }
            if( 3 * i % (fst + snd) != 0){
                cout<<i<<" ";
                cont++;
                fst = snd;
                snd = i;
            }
        }
        cout<<"\n";
    }
    return 0;
}