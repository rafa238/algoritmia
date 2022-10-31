//https://codeforces.com/gym/103960/problem/E
#include<bits/stdc++.h>
using namespace std;

int main(){
    long long int n; cin>>n;
    vector<int> arrows(10e6+1, 0);
    for(long long int i=0; i<n; i++){
        long long int h; cin>>h;
        if(arrows[h+1] != 0){
            arrows[h+1]--;
        }
        arrows[h]++;
    }
    long long int cont = 0;
    for(long long int i=0; i<arrows.size(); i++){
        cont += arrows[i];
    }
    cout<<cont<<endl;
}