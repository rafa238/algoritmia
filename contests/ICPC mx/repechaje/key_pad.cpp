#include<bits/stdc++.h>
using namespace std;
vector<char> keyPad = {'2', '2', '2', '3', '3', '3', '4', '4', '4', '5', '5', '5', '6', '6', '6', '7', '7', '7', '7', '8', '8', '8', '9', '9', '9', '9'};

int main(){
    int n,q; cin>>n>>q;
    string identifier, code;
    unordered_map<string, int> dict;

    for(int i=0; i<n; i++){
        string identifierStr = "";
        cin>>identifier;
        for(auto letter: identifier){
            identifierStr += keyPad[letter - 'a'];
        }
        dict[identifierStr] += 1;
    }

    for(int i=0; i<q; i++){
        cin>>code;
        cout<<dict[code]<<endl;
    }
    return 0;
}