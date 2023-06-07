#include<bits/stdc++.h>
using namespace std;

int main(){
    string s; cin>>s;
    char prevChar = s[0];
    int bestSize = 1, currSize = 1;
    for(int i=1; i<s.size(); i++){
        if(s[i] == prevChar){
            currSize++;
        } else{
            currSize = 1;
            prevChar = s[i];
        }
        bestSize = max(bestSize, currSize);
    }
    cout<<bestSize;
    return 0;
}