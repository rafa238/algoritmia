#include<bits/stdc++.h>
//https://atcoder.jp/contests/agc020/tasks/agc020_a
using namespace std;

int main(){
    int n, a, b;
    cin>>n>>a>>b;
    if((b-(a+1)) % 2 == 0){
        cout<<"Borys";
    } else {
        cout<<"Alice";
    }
    cout<<endl;
}