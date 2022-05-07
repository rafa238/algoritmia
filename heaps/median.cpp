#include<bits/stdc++.h>

using namespace std;

int main(){
    vector<int> numeros;
    int N; cin>>N;
    for (int i = 0; i < N; i++){
        int n; cin>>n;
        numeros.push_back(n);
        sort(numeros.begin(), numeros.end());
        double mediana;
        if (i % 2 == 0){ 
            mediana = numeros[i / 2];
        }
        else{
            mediana = static_cast<double>( (numeros[i / 2] + numeros[i / 2 + 1])) / 2;
        }
        cout << mediana << "\n";
    }
    
}