#include<bits/stdc++.h>
using namespace std;

int main(){
    int n; cin>>n;
    //map<int, bool> arrows;
    vector<bool> arrows(10e7, false);
    long long int cont=0; 
    for(long long int i=0; i<n; i++){
        long long int h; cin>>h;
        if(h == 0) continue;
        if(!arrows[h]){
            cont++;
        } 
        arrows[h] = false;
        if(h-1 > 0)arrows[h-1] = true;
    }
    cout<<cont<<endl;
}