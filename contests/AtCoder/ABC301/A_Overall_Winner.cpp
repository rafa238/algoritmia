#include<bits/stdc++.h>

using namespace std;

int main(){
    string s;
    int n; 
    cin>>n>>s;
    int t = 0, a = 0; 
    for(auto elem : s){
        if(elem == 'T') t++;
        else a++;
    }
    if(a>t){
        cout<<"A";
    } else if ( t>a){
        cout<<"T";
    } else {
        int na, nt;
        na = nt = 0;
        for(auto elem : s){
            if(elem == 'T') nt++;
            else na++;

            if(nt == t){
                cout<<"T";
                break;
            } else if(na == a) {
                cout<<"A";
                break;
            }
        }
    }
    cout<<"\n";
    return 0;
}