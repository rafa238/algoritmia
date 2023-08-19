#include <bits/stdc++.h>

using namespace std;

char applyCase(char c, int type){
    char ans = c;
    if(type == 2){
        ans = (char)tolower(c);
    } else if( type == 3){
        ans = (char)toupper(c);
    }
    return ans;
}

int main() {
    int n;
    cin >> n;
    vector<char> s(n);
    pair<int, int> all =  make_pair(-1, -1);
    vector<pair<char, int>> operations(n);
    for(int i=0; i<s.size(); i++){
        cin>>s[i];
        operations[i] = make_pair('a', -1);
    }

    int numOfAction = 0;
    int q; cin>>q;
    while(q--){
        int typeQ, pos;
        char c;
        cin>>typeQ>>pos>>c;
        if(typeQ == 1){
            operations[pos-1] = make_pair(c, numOfAction++);
        } else{
            all = make_pair(typeQ, numOfAction++);
        }
    }

    for(int i=0; i<n; i++){
        if(operations[i].second != -1){
            if(operations[i].second > all.second){
                s[i] = operations[i].first;
            } else {
                s[i] = applyCase(operations[i].first, all.first);
            }
        } else {
            s[i] = applyCase(s[i], all.first);
        }
    }
    for(char elem : s){
        cout<<elem;
    }
    return 0;
}

