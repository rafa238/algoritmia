#include<bits/stdc++.h>
using namespace std;

int main(){
    int N; cin>>N;
    set<int> precios;
    for (int i = 0; i < N; i++){
        int precio; cin>>precio;
        precios.insert(precio);
    }   
    int index = 0; 
    int mediano = INT_MIN;
    for(set<int>::iterator begin = precios.begin(); begin != precios.end(); begin++){
        if(index==1){
            mediano=*begin;
            break;
        }
        index++;
    }
    if(mediano != INT_MIN) cout<<mediano;
    else cout<<"NO";
    return 0;
}