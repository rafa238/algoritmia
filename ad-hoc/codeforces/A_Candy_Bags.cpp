#include <bits/stdc++.h>
//https://codeforces.com/contest/334/problem/A
using namespace std;

int main(){
    int n; cin>>n;
    int bags = n*n;
    for(int i=1, j=bags, z=0; i<=bags/2;){
        
        cout<< i << " " << j << " ";
        i += 1;
        j -= 1;
        z+=2;
        if(z==n) {
            z = 0;
            cout<<endl;
        }
    }

    
    return 0;
}