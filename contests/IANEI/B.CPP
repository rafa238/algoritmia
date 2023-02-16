#include<bits/stdc++.h>
using namespace std;

int main(){

    int n,b; cin>>n>>b;
    while(n != 0 && b != 0){
        int ballons = 0;
        for(int i=0;i<n; i++){
            int elem; cin>>elem;
            ballons += elem;
        }
        int ans = b/ballons;
        cout<<ans<<endl;
        cin>>n>>b;
    }
    
    
    
}