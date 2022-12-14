
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int> criba_lineal(int n){
    vector<int> lp(n + 1);
    vector<int> primos;
    for(int i = 2; i <= n; i++){
        if(lp[i] == 0){
            lp[i] = i;
            primos.push_back(i);
        }
        for(int j=0; primos[j] * i < n; j++){
            lp[ i * primos[j]] = primos[j];
            if( primos[j] == lp[i] )
                break;
        }
    }
    return lp;
}

vector<int> mu(int n) {
    ios_base::sync_with_stdio(0); cin.tie();

    vector<int> lp = criba_lineal(n);
    vector<int> mu1(n+1);
    mu1[1] = 1;
    for(int i=2; i<=n; i++){
        if (i % (lp[i] * 1ll *lp[i]) == 0){
            mu1[i]=0;
        }else{
            mu1[i] = -mu1[i/lp[i]];
        }
    }
    return mu1;
}

int main(){
    int num;
    int maxn = 100000000;
    vector<int> ans = mu(maxn);
    while(true){
            cin>>num;
            if(num==0) break;
            cout<<ans[num]<<"\n";
    }
}