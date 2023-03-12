#include<bits/stdc++.h>
//https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=608&page=show_problem&problem=2726
using namespace std;
typedef long long ll;

int main(){
    int banks, debentures, debtor, acreditor, value;

    while(cin>>banks>>debentures, banks != 0 && debentures != 0){
        vector<int> reserves(banks+1);

        for(int i=1; i<=banks; i++){
            cin >> reserves[i];
        }

        for(int i=0; i<debentures; i++){
            cin >> debtor >> acreditor >> value;
            reserves[debtor] -= value;
            reserves[acreditor] += value;
        }

        bool ans = true;

        for(int i=0; i<reserves.size(); i++){
            if(reserves[i] < 0){
                ans = false;
                break;
            }
        }

        cout<<((ans) ? "S" : "N")<<endl;
    }
    
    return 0;
}