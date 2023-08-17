#include <bits/stdc++.h>

using namespace std;

int main(){
    int n; cin>>n;
    vector<unordered_set<int>> people(n, unordered_set<int>());
    for(int i=0; i<n; i++){
        int ci; cin>>ci;
        for(int j = 0; j<ci; j++){
            int bet; cin>>bet;
            people[i].insert(bet);
        }
    }
    int X; cin>>X;
    vector<pair<int, int>> ans;
    for(int i=0; i<n; i++){
        if(people[i].count(X) != 0){
            ans.push_back({people[i].size(), i});
        }
    }
    sort(ans.begin(), ans.end());
    int pointer = 0;
    for(auto elem : ans){
        if(elem.first != ans[0].first){
            break;
        }
        pointer++;
    }
    cout<<pointer<<"\n";
    for(int i=0; i < pointer; i++){
        cout<<ans[i].second + 1<<" ";
    }
    cout<<"\n";
    return 0;
}