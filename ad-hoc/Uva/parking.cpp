#include<bits/stdc++.h>
using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        int min = INT_MAX, max = INT_MIN;
        while(n--){
            int store; cin>>store;
            
            if(store > max){
                max = store;
            } 
            if(store<min){
                min = store;
            }
            
        }
       cout<<(max-min)*2<<endl;
    }
}