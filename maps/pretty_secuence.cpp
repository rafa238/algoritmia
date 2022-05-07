#include<bits/stdc++.h>
using namespace std;

int main(){
    map<int, int> mapita;
    int N; cin>>N;
    for(int i=0; i<N; i++){
        int num; cin>>num;
        if(mapita.count(num)) mapita[num]++;
        else mapita[num] = 1;
    }
    auto iter = mapita.begin();
    int ocurrencias = 0;
    while (iter != mapita.end()) {
        if(iter->first > iter->second){
            ocurrencias += iter->second;
        } else if(iter->first < iter->second){
            ocurrencias += iter->second - iter->first;
        }
        ++iter;
    }
    cout<< ocurrencias;
    return 0;
}