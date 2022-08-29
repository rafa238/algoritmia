#include <bits/stdc++.h>
#include <set>
using namespace std;

int main(){
    int N; cin>>N;
    while(N--){
        string t1, t2;
        cin>>t1;
        set <char> set_name(t1.begin(), t1.end());
        for (auto i : set_name)
            cout << i << " ";
    }
}