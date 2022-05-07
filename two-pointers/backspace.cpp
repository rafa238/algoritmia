#include <bits/stdc++.h>
using namespace std;

string quitar(string cadena){
    char buffer[100];
    strcpy(buffer, cadena.c_str());
    
}

bool stringdp(map<string, bool> &dp, string cadena, string target){
    if(target == cadena) return true;
    if(dp.count(cadena)) return dp[cadena];
    
    for(int i=0; i<cadena.size(); i++) {
        
        return stringdp(dp, cadena, target);
    }
    //return stringdp(dp, cadena, target) ||  stringdp(dp, cadena, target) || stringdp(dp, cadena, target) || stringdp(dp, cadena, target);
}

int main(){
    int n;
    vector<string> dp;
    map<string, string> pares;

    cin>>n;
        for(int i=0;i<n;i++){
        string cadena, buscado;
        cin>>cadena>>buscado;
        //cout<<"insertado: "<<cadena<<endl;
        pares.insert({cadena, buscado});
    }

    return 0;
}