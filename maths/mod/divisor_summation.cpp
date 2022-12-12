//https://www.spoj.com/problems/DIVSUM/
#include<bits/stdc++.h>
using namespace std;

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
    vector<int> lp = criba_lineal(n);
    vector<int> sigma1(n);
    sigma1[1] = 1;
    for(int i=2; i<n; i++){
        int a = i, b = 1, k = 0;
        while(a % lp[i] == 0){
            a /= lp[i], b *= lp[i];
            k++;
        }
        if(a==1) sigma1[i] = (pow(lp[i], k+1)-1)/(lp[i]-1);
        //if(a==1) sigma1[i] = k+1;
        else sigma1[i] = sigma1[a] * sigma1[b] ;
        //cout<<sigma1[i-1]-i<<" ";
    }
    return sigma1;
}

int main(){
    int tc;
    cin>>tc;
    int ax = 5000000+9;
    vector<int> ans = mu(ax);
    int num;
    while(tc--){
        cin>>num;
        cout<<ans[num]-num<<"\n";
    }
}