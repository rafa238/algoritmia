#include<bits/stdc++.h>
//https://codeforces.com/gym/101981/attachments
using namespace std;

int main(){
    int n, k;
    cin>>n>>k;


    if(n==0){
        cout<<"Austin";
    } else if(n<=k){
        cout<<"Adrien";
    } else if( k == 1) {
        if(n%2 == 0){
            cout<<"Austin";
        } else {
            cout<<"Adrien";
        }
    } else if(k>=2){
        cout<<"Adrien";
    }
    cout<<endl;
}