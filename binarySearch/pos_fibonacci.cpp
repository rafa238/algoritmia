#include <iostream>
using namespace std;
//https://omegaup.com/course/introduccion_a_algoritmos/assignment/busqueda_binaria#problems/Posicion-Fibonacci

int fibonacci(int n){
    
}

int bs(int fibo[], int n){
    int l=0, r=(n+5)-1;
    while(l <= r){
        int t = (r + l) / 2;
        if(fibo[t] == n){
            return t+1;
        } else if(fibo[t] < n){
            l = t+1;
        } else {
            r = t-1;
        }
    }
    return 0;
}

int main(){
    return 0;
}