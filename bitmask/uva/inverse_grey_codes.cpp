#include<bits/stdc++.h>
using namespace std;
/*
    Uva 11173 - Grey Codes
*/
int main(){

    int N; cin>>N;
    int ans = N^((N|(N>>1))>>1);
    cout<<ans<<endl;

}