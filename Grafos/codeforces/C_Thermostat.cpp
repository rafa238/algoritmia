#include <bits/stdc++.h>
using namespace std;


int main(){
    int tc; cin>>tc;
    while(tc--){
        int l, r, x, a, b;
        cin >> l >> r >> x;
        cin >> a >> b;
        if(a == b){
            cout<<"0\n";
        }
        if(abs(a-b) >= x ){
            cout << "1 \n";
            continue;
        }
        if(a > b){
            swap(a, b);
        }
        if(a < b){
            //ire a la izquierda
            if(abs(l-a) >= x){
                //ire a b
                if(abs(l-b) >= x){
                    cout << "2\n";
                    continue;
                }
                //ire hasta r desde l
                if(abs(r-l) >= x){
                    if(abs(r-b) >= x){
                        cout << "3\n";
                        continue;
                    }
                }
            }
            //ire a la derecha
            if(abs(r-a) >= x){
                //ire a b
                if(abs(r-b) >= x){
                    cout << "2\n";
                    continue;
                }
                //ire hasta l desde r
                if(abs(r-l) >= x){
                    if(abs(l-b) >= x){
                        cout << "3\n";
                        continue;
                    }
                }
            }
            cout<<"-1\n";
        }

        
    }
    return 0;
}