#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;

bool potencia(ll N){
    ll ne = N&(-N);
    return ne == N;
}

int main(){
    ll N; cin>>N;
    vector<ll> numbers;
    map<ll, ll> frecuencies;
    vector<ll> potencies;

    for(ll i=0; i<N; i++){
        ll elem; cin>>elem;
        numbers.push_back(elem);
        frecuencies[elem]++;
    }

    //only has at least 30 elements
    ll potencie=1;
    while(potencie<=10e9){
        potencie*=2;
        potencies.push_back(potencie);
    }

    ll cont = 0;
    for(auto num : numbers){
        //cout<<num<<" ";
        for(auto poten: potencies){
            //cout<<"poten: "<<potencies.size()<<" ";
            ll aux = poten-num;
            if(frecuencies[aux]){
                if(num == aux) cont += (frecuencies[aux]-1);
                else cont += (frecuencies[aux]);
            }
        }
    }
    cout<<cont/2<<endl;

    return 0;
}

/*
    for(ll i=0; i<N; i++){
        for(ll j=0; j<N; j++){
            if(i==j)continue;
            ll sum = vec[i] + vec[j];
            if(mp[sum] == 1){
                cont++;
            } else if(mp[sum] == 2) {
                continue;
            } else {
                bool ispo = potencia(sum);
                if(ispo){
                    mp[sum] = 1;
                    cont++;
                } else {
                    mp[sum] = 2; 
                }
            }
        }
    }

*/