#include<bits/stdc++.h>
using namespace std;

int main(){
    long long n, elem, prev, cont =0; cin>>n;
    bool fstIteration = true;
    for(int i=0; i<n; i++){
        if(fstIteration){
            fstIteration = !fstIteration;
            cin>>prev;
            continue;
        }
        cin>>elem;
        if((prev - elem  ) > 0){
            cont += prev-elem;
            prev = elem + prev - elem;
        } else {
            prev = elem;
        }
        
    }
    cout<<cont<<"\n";
    return 0;
}