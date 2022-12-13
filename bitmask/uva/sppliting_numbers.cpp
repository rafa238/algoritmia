//https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=626&page=show_problem&problem=3084
#include <bits/stdc++.h>
using namespace std;

int lowBit(int S) { 
    return S & (-S); 
}

int main(){
    int n;cin>>n;
    while(n != 0){
        int num = n;
        int a=0, b=0, cont = 0;
    
        while(num!=0){
            int lsb = lowBit(num);
            if((++cont)%2 != 0){
                a = a|lsb;
            } else {
                b = b|lsb;
            }
            num = num ^ lsb;
        }
        cout<< a << " " << b << endl;
        cin>>n;
    }
    return 0;
}