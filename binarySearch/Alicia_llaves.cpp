#include<iostream>

int bs(int llave, int chapas[], int P){
    int l=0, r=P-1;
    while(l <= r){
        int t = (r + l)/2;
        if(chapas[t] == llave){
            return t+1;
        } else if(chapas[t] < llave){
            l = t+1;
        } else {
            r = t-1;
        }
    }
    return 0;
}

int main(){
    int P; std::cin>>P;
    int chapas[P];
    for (int i =0; i<P; i++){
        int chapa; std::cin>>chapa;
        chapas[i] = chapa;
    }
    int L; std::cin>>L;
    while (L--){
        int llave; std::cin>>llave;
        std::cout<<bs(llave, chapas, P)<<" ";
    }
    return 0;
}