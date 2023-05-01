#include<bits/stdc++.h>
using namespace std;

int main(){
    int tc, k;
    string s;
    cin>>tc;
    
    while(tc--){
        cin>>s>>k;
        string number = "0";
        long long cont = 0;
        for(char c: s){
            if(c >= '0' && c <= '9'){
                number += c;
            } else {
                long long numberCast = stoll(number);
                if(numberCast == 0){
                    cont++;
                } else {
                    cont += numberCast;
                }
                number = "0";
            }
        }
        
        if(cont>k){
            cout<<"unfeasible"<<endl;
        } else {
            number = "0";
            for(char c: s){
                if(c >= '0' && c <= '9'){
                    number += c;
                } else {
                    long long numberCast = stoll(number);
                    for(long long i=0; i<numberCast-1; i++){
                        cout<<c;
                    }
                    cout<<c;
                    number = "0";
                }
            }
            cout<<endl;
        }
    }
    return 0;
}