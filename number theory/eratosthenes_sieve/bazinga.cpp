//https://www.spoj.com/problems/DCEPC505/
#include <bits/stdc++.h>
using namespace std;

const int maxn = 10600000;

vector<int> primos;
vector<int> criba_lineal(int n){
    vector<int> lp(n + 1, 0);
    for(int i = 2; i <= n; i++){
        if(lp[i] == 0){
            lp[i] = i;
            primos.push_back(i);
        }
        for(int j=0; primos[j] * i <= n; j++){
            lp[ i * primos[j]] = primos[j];
            if( primos[j] == lp[i] )
                break;
        }
    }
    return lp;
}

vector<int> semiprimos;
void noDivisors(vector<int> &lp){
    for(int in=2; in<maxn; in++){
        int p1, p2, i=in;
        p1 = lp[i];
        //cout<<i<<" : "<<p1<<" ";
        i /= lp[i];
        if(i == 1) {
            //cout<<endl; 
            continue;
        }
        p2 = lp[i];
        i /= lp[i];
        //cout<<p2<<endl;
        if(i == 1 && p1 != p2){
            //cout<<"push"<<endl;
            semiprimos.push_back(in);
        }
    }
} 

int main(){
    int tc; cin>>tc;
    vector<int> lp = criba_lineal(maxn);
    noDivisors(lp);
    //cout<<semiprimos.size();
    while(tc--){
        int n;
        cin>>n;
        cout<<semiprimos[n-1]<<endl;
    }
    
    return 0;
}