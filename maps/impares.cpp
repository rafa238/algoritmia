#include<bits/stdc++.h>
using namespace std;

int main(){
    int N; cin>>N;
    while(N--){
        set<int, greater<int>> enteros;
        int n; cin>>n;
        for(int i=0; i<n; i++){
            int num; cin>>num;
            enteros.insert(num);
        }
        int num = 0;
        while(*enteros.begin()%2 == 0){
            int inicio =*enteros.begin();
            inicio /= 2;
            enteros.erase(*enteros.begin());
            enteros.insert(inicio);
            num++;
        }
        /*for(set<int>::iterator begin = enteros.begin(); begin != enteros.end(); begin++){
            cout<<*begin;
        }*/
        cout<<"numero de operaciones: "<<num<<endl;
    }
    return 0;
}