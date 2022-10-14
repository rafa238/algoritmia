#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
    int t;
    cin>>t;
    while (t--){
        int pares=0, impares=0;
        int n;
        cin>>n;
        for (int i = 0; i < n; i++) {
            int elem; cin>>elem;
            if(elem%2==0){
                pares++;
            } else {
                impares++;
            }
        }
        cout<<min(pares, impares)<<endl;
    }
}