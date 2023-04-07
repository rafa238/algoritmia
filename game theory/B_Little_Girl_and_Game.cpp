#include<bits/stdc++.h>
//https://codeforces.com/problemset/problem/276/B
using namespace std;

int main(){
    string s;
    cin>>s;
    vector<int> freq(27, 0);
    for(auto c: s){
        freq[c-'a']++;
    }
    int odd = 0;
    for(int f : freq){
        if(f % 2 != 0) odd++;
    }
    odd--;
    if(odd%2 == 0 || odd == -1){
        cout<<"First";
    } else {
        cout<<"Second";
    }
}