#include<bits/stdc++.h>
using namespace std;

int main(){
    long long int n; cin>>n;
    //map<int, bool> arrows;
    long long int cont = 0;
    vector<int> arrows(10e6+1, 0);
    for(long long int i=0; i<n; i++){
        long long int h; cin>>h;
        if(arrows[h+1] == 0){
            arrows[h] = 1;
            cont++;
        }
        arrows[h+1] = 0;
        arrows[h] = 1;
    }
    cout<<cont<<endl;
}