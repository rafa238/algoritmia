#include<bits/stdc++.h>
using namespace std;


int main(){
    int N, X; cin>>N>>X;
    unordered_set<int> s;
    vector<int> friends(N);
    for(int i=0; i<N; i++){
        int elem; cin>>elem;
        friends[i] = elem;
    }
    for(int i=0; i<friends.size(); i++){
        for(int j=friends[i]; j<=X; j+=friends[i]){
            s.insert(j);
        }
    }
    cout<<s.size()<<endl;
    /*for(auto elemento: s){
        cout<<elemento<<" ";
    }*/
}