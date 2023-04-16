#include<bits/stdc++.h>
#define fstIO ios_base::sync_with_stdio(0); cin.tie(0);
using namespace std;
typedef vector<int> vi;
typedef long long ll;

int main(){
    fstIO;
    ll n;
    cin>>n;
    if(n%2 == 0){
        cout<<"white"<<endl;
        cout<<"1 2"<<endl;
    } else {
        cout<<"black"<<endl;
    }
    return 0;
}